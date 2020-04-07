/*************************************************************************************
 * @name     :    player.h
 *
 * @brief    :    media player sample class
 *
 * @author   :    ashish
 *
 * @date     :    03-Apr-2020
 *
 * @copyright:    (C) 2020 KPIT Technologies Ltd.
 *                Created in 2020 as an unpublished copyright work.
 *                All rights reserved.
 *                Provided under the terms of KIVI Agreement.
 *                This source code file is proprietary to KPIT Technologies Limited.
 *                It may not be used, copied, reproduced, transmitted, or stored
 *                in any form or by any means, electronic, recording, photocopying,
 *                mechanical or otherwise, without the prior written permission of
 *                KPIT Technologies Limited.
 *
 *************************************************************************************/

#ifndef MEDIAFFMPEG_SKIPE_PLAYER_H_
#define MEDIAFFMPEG_SKIPE_PLAYER_H_
#include "../include/mediaffmpegTypes.h"
#include "streampacket.h"
extern "C"
{
#include<libavformat/avio.h>
#include<libavutil/samplefmt.h>
}


/**
 *
 */
#define AVCODEC_MAX_AUDIO_FRAME_SIZE   192000

namespace ffmpeg = media::ffmpeg;
namespace media {
namespace test {

using metadata_t=struct metadata_t{
	std::string title;
	std::string album;
	std::string artist;
	uint64_t duration;
	std::string filename;
	std::string coverartPath;
};

enum stream_index_t{
	STREAM_INDEX_AUDIO,
	STREAM_INDEX_VIDEO,
	STREAM_INDEX_SUBTITLE,
	STREAM_MAX_INDEX
};

using stream_state_t=struct stream_state_t{
  ffmpeg::boolean_t abort_request;
  ffmpeg::boolean_t paused;
  ffmpeg::boolean_t seekRequest;
  int64_t seekPos;
  int64_t seekRel;
  std::string filename;
  SDL_Thread* parse_tid;
  int m_StreamIndex[STREAM_MAX_INDEX];
  AVFormatContext* m_formatCntx;
  int audioHwBufSize;
  int audioSrcFormat;
  AVStream* avstream;
  unsigned int audioBufSize;
  int audioBufIndex;
  AVPacket audioPktTemp;
  AVPacket audioPkt;
  DECLARE_ALIGNED(16,uint8_t,audio_buf1)[(AVCODEC_MAX_AUDIO_FRAME_SIZE * 3) / 2];
  DECLARE_ALIGNED(16,uint8_t,audio_buf2)[(AVCODEC_MAX_AUDIO_FRAME_SIZE * 3) / 2];

};

class Player final {
   public:
    /**
 *
 */
    Player();
    /**
     *
     */
    ~Player();
    /**
     *
     * @param t_instance
     */
    Player(const Player& t_instance);
    /**
     *
     * @param t_instance
     */
    Player(Player&& t_instance);
    /**
     *
     * @param t_instance
     * @return
     */
    Player& operator=(const Player& t_instance);
    /**
     *
     * @param t_instance
     * @return
     */
    Player& operator=(Player&& t_instance);

   public:
    auto startPlayback(std::string& sourcename, int bufferSize) -> ffmpeg::media_error_t;
    auto initiaizeMedia() -> ffmpeg::media_error_t;
    auto playMedia() -> ffmpeg::media_error_t;
    auto pauseMedia() -> ffmpeg::media_error_t;
    auto seekMedia() -> ffmpeg::media_error_t;
    auto fastForwardMedia() -> ffmpeg::media_error_t;
    auto fastReverseMedia() -> ffmpeg::media_error_t;
    auto stopMedia() -> ffmpeg::media_error_t;

   public:
    ffmpeg::media_error_t getMetadata(metadata_t& t_instance);
    ffmpeg::media_error_t getStreamInfo();

    ffmpeg::media_error_t streamComponentOpen(int t_index);
    ffmpeg::media_error_t streamComponentClose(int t_index);
    int audioFrameDecode(double *pts_ptr);

   public:
    stream_state_t m_StreamState;
    StreamPacketQueue *m_streamPacketQueue;
    AVPacket *flushPacket{nullptr};


};
static int decodeStream(void* t_instance);
static void AudioCallback(void *data, uint8_t *stream, int streamLength);
}  // namespace test
}  // namespace media

#endif /* MEDIAFFMPEG_SKIPE_PLAYER_H_ */
