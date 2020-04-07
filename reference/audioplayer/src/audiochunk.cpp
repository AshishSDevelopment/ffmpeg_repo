#include "audiochunk.h"

#include <libavutil/opt.h>
#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

static void _freeAudioChunk(AudioChunk **chunk);

AudioChunkQueue* createAudioChunkQueue(int maxCapacity)
{
    AudioChunkQueue *queue = new AudioChunkQueue();
    queue->first = NULL;
    queue->last = NULL;
    queue->quantity = 0;
    queue->capacity = maxCapacity;
    queue->mutex = (pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER;
    
    sem_unlink("/full");
    sem_unlink("/empty");
    
    queue->full = sem_open("/full", O_CREAT, 0644, 0);
    queue->empty = sem_open("/empty", O_CREAT, 0644, maxCapacity);
    
    return queue;
}

int insertAudioChunk(AudioChunk *chunk, AudioChunkQueue *queue)
{
    if (queue == NULL) {
        return 0;
    }
    
    AudioChunkList *newChunkList = new AudioChunkList();
    newChunkList->chunk = chunk;
    newChunkList->next = NULL;
    
    sem_wait(queue->empty);
    
    pthread_mutex_lock(&queue->mutex);
    
    if (queue->quantity == 0) {
        queue->first = newChunkList;
    } else {
        queue->last->next = newChunkList;
    }
    queue->last = newChunkList;
    
    queue->quantity++;
    
    pthread_mutex_unlock(&queue->mutex);
    
    sem_post(queue->full);
    
    return 1;
}

int getNextAudioChunk(AudioChunk **chunk, AudioChunkQueue *queue, int howManyBytes)
{
    if (queue == NULL) {
        return 0;
    }
    
    sem_wait(queue->full);
    pthread_mutex_lock(&queue->mutex);
    
    AudioChunkList *first = queue->first;
    if (first->chunk->size <= howManyBytes) {
        *chunk = first->chunk;
        queue->first = queue->first->next;
        
        queue->quantity--;
        if (queue->quantity == 0) {
            queue->first = NULL;
            queue->last = NULL;
        }
        
        free(first);
        sem_post(queue->empty);
    } else {
        sem_post(queue->full);
        
        *chunk = new AudioChunk();
        (*chunk)->size = howManyBytes;
        (*chunk)->data = (uint8_t*)malloc(howManyBytes);
        memcpy((*chunk)->data, first->chunk->data, howManyBytes);
        
        first->chunk->size -= howManyBytes;
        uint8_t *remainingData = (uint8_t*)malloc(first->chunk->size);
        memcpy(remainingData, first->chunk->data + howManyBytes, first->chunk->size);
        free(first->chunk->data);
        first->chunk->data = remainingData;
    }
    
    pthread_mutex_unlock(&queue->mutex);
    
    return 1;
}

void flushAudioChunkQueue(AudioChunkQueue *queue, int shouldUnlockMutex)
{
    pthread_mutex_lock(&queue->mutex);
    
    AudioChunkList *chunkList = queue->first;
    while (chunkList != NULL) {
        AudioChunkList *next = chunkList->next;

        _freeAudioChunk(&chunkList->chunk);
        free(chunkList);

        chunkList = next;
        
        sem_wait(queue->full);
        sem_post(queue->empty);
    }
    
    queue->first = NULL;
    queue->last = NULL;
    queue->quantity = 0;
    
    if (shouldUnlockMutex) {
        pthread_mutex_unlock(&queue->mutex);
    }
}

void freeAudioChunkQueue(AudioChunkQueue **queue)
{
    flushAudioChunkQueue(*queue, 0);
    
    sem_unlink("/full");
    sem_unlink("/empty");
    
    sem_close((*queue)->full);
    sem_close((*queue)->empty);
    
    pthread_mutex_destroy(&(*queue)->mutex);
    
    free(*queue);
    *queue = NULL;
}

void _freeAudioChunk(AudioChunk **chunk)
{
    free((*chunk)->data);
    free(*chunk);
}
