/*
 * streampacket.cpp
 *
 *  Created on: 03-Apr-2020
 *      Author: ashish
 */

#include "streampacket.h"
namespace media {
namespace test {

StreamPacketQueue::StreamPacketQueue()noexcept:m_firstPkt(nullptr),m_lastPkt(nullptr),m_nbpackets(0),m_Size(0),m_AbortRequest(ffmpeg::boolean_t::FALSE),m_Mutex(nullptr),m_Cond(nullptr){}
StreamPacketQueue::~StreamPacketQueue()noexcept{}
StreamPacketQueue::StreamPacketQueue(const StreamPacketQueue& t_instance)noexcept{}
StreamPacketQueue::StreamPacketQueue(StreamPacketQueue&& t_instance)noexcept{}
StreamPacketQueue& StreamPacketQueue::operator=(const StreamPacketQueue& t_instance)noexcept{
	return (*this);
}
StreamPacketQueue& StreamPacketQueue::operator=(StreamPacketQueue&& t_instance)noexcept{
	return (*this);
}

ffmpeg::media_error_t StreamPacketQueue::packetQueueInit(){
	std::cout<<"enter in StreamPacketQueue::packetQueueInit\n";
	 this->m_Mutex = SDL_CreateMutex();
	this->m_Cond = SDL_CreateCond();
	packetQueuePut(&flush_pkt);
	return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
int StreamPacketQueue::packetQueuePut(AVPacket *t_pkt){
//	std::cout<<"enter in StreamPacketQueue::packetQueuePut with nbpackets: "<<this->m_nbpackets<<"\n";
	 AVPacketList *pkt1;
     /* duplicate the packet */
   if (t_pkt!=&flush_pkt && av_dup_packet(t_pkt) < 0)
	return -1;

    pkt1=new AVPacketList();
  if (!pkt1){
   return -1;}
   pkt1->pkt = *t_pkt;
  pkt1->next = nullptr;
  SDL_LockMutex(this->m_Mutex);
   if (!this->m_lastPkt){
    this->m_firstPkt = pkt1;
   }
   else{
     this->m_lastPkt->next = pkt1;
   }
   this->m_lastPkt = pkt1;
   this->m_nbpackets++;
    this->m_Size += pkt1->pkt.size + sizeof(*pkt1);
     /* XXX: should duplicate packet data in DV case */
 SDL_CondSignal(this->m_Cond);
 SDL_UnlockMutex(this->m_Mutex);
	return 0;
}

ffmpeg::media_error_t StreamPacketQueue::packetQueueFlush(){
	AVPacketList *pkt, *pkt1;
	  SDL_LockMutex(this->m_Mutex);
	for(pkt = this->m_firstPkt; pkt != nullptr; pkt = pkt1) {
	    pkt1 = pkt->next;
	      av_free_packet(&pkt->pkt);
	        av_freep(&pkt);
	      }
	this->m_lastPkt = nullptr;
	 this->m_firstPkt = nullptr;
	 this->m_nbpackets = 0;
	 this->m_Size = 0;
	SDL_UnlockMutex(this->m_Mutex);

	return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
ffmpeg::media_error_t StreamPacketQueue::packetQueueEnd(){
	packetQueueFlush();
	SDL_DestroyMutex(this->m_Mutex);
	SDL_DestroyCond(this->m_Cond);
	return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
ffmpeg::media_error_t StreamPacketQueue::packetQueueAbort(){
	SDL_LockMutex(this->m_Mutex);
	 this->m_AbortRequest = ffmpeg::boolean_t::TRUE;
	 SDL_CondSignal(this->m_Cond);
	 SDL_UnlockMutex(this->m_Mutex);
	return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
int StreamPacketQueue::packetQueueGet(AVPacket *t_pkt, int t_block){

	     AVPacketList *pkt1;
	     int ret;

	     SDL_LockMutex(this->m_Mutex);

	     while(1){
	         if (this->m_AbortRequest==ffmpeg::boolean_t::TRUE) {
	             ret = -1;
	             break;
	         }

	         pkt1 = this->m_firstPkt;
	         if (pkt1) {
	        	 this->m_firstPkt = pkt1->next;
	             if (!this->m_firstPkt)
	            	 this->m_lastPkt = nullptr;
	             this->m_nbpackets--;
	             this->m_Size -= pkt1->pkt.size + sizeof(*pkt1);
	             *t_pkt = pkt1->pkt;
	             av_free(pkt1);
	             ret = 1;
	             break;
	         } else if (!t_block) {
	            ret = 0;
	            break;
	         } else {
	           SDL_CondWait(this->m_Cond, this->m_Mutex);
	        }
	}
SDL_UnlockMutex(this->m_Mutex);
	return ret;
	}
AVPacket* StreamPacketQueue::getFLushPacket(){
	return &flush_pkt;
}

}  // namespace test
}  // namespace media

