/*************************************************************************************
 * @name     :    streampacket.h
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

#ifndef MEDIAFFMPEG_SKIPE_STREAMPACKET_H_
#define MEDIAFFMPEG_SKIPE_STREAMPACKET_H_

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavformat/avio.h>
#include <libswscale/swscale.h>
#include <libavdevice/avdevice.h>
#include <libavfilter/avfilter.h>
#include <libavutil/dict.h>
#include <SDL/SDL.h>
}
#include"../include/mediaffmpegTypes.h"
namespace media {
namespace test {

namespace ffmpeg=media::ffmpeg;

class StreamPacketQueue final{

public:
	StreamPacketQueue()noexcept;
	~StreamPacketQueue()noexcept;
	StreamPacketQueue(const StreamPacketQueue& t_instance)noexcept;
	StreamPacketQueue(StreamPacketQueue&& t_instance)noexcept;
	StreamPacketQueue& operator=(const StreamPacketQueue& t_instance)noexcept;
	StreamPacketQueue& operator=(StreamPacketQueue&& t_instance)noexcept;

public:
	ffmpeg::media_error_t packetQueueInit();
	int packetQueuePut(AVPacket *t_pkt);
	ffmpeg::media_error_t packetQueueFlush();
	ffmpeg::media_error_t packetQueueEnd();
	ffmpeg::media_error_t packetQueueAbort();
	int packetQueueGet(AVPacket *t_pkt, int t_block);

	AVPacket* getFLushPacket();

private:
   AVPacketList* m_firstPkt;
   AVPacketList* m_lastPkt;
   int m_nbpackets;
   int 	m_Size;
   ffmpeg::boolean_t m_AbortRequest;
   SDL_mutex * 	m_Mutex;
   SDL_cond * 	m_Cond;
   AVPacket flush_pkt;
};



}  // namespace test
}  // namespace media


#endif /* MEDIAFFMPEG_SKIPE_STREAMPACKET_H_ */
