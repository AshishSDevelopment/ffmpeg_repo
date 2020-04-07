/*************************************************************************************
 * @name     :    mediaffmpegimpl.h
 *
 * @brief    :    media ffmpeg implemetation for client
 *
 * @author   :    ashish.
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

#ifndef MEDIAFFMPEG_SRC_MEDIAFFMPEGIMPL_H_
#define MEDIAFFMPEG_SRC_MEDIAFFMPEGIMPL_H_

#include "../include/mediaffmpegTypes.h"

/**
 * @details: third party c header files libav
 */
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
/**
 * @details: namespace for media ffpeg implementation.
 */

namespace media {
namespace ffmpeg {

/**
 * @details: media-ffmpeg implementation final class which is not inherited by
 * other class.
 */
class MediaFFMPEGImpl final {
   public:
    /**
     *
     */
    MediaFFMPEGImpl() noexcept;
    /**
     *
     */
    ~MediaFFMPEGImpl() noexcept;
    /**
     *
     * @param t_instance
     */
    MediaFFMPEGImpl(const MediaFFMPEGImpl& t_instance) noexcept;
    /**
     *
     * @param m_instance
     */
    MediaFFMPEGImpl(MediaFFMPEGImpl&& t_instance) noexcept;
    /**
     *
     * @param t_instance
     * @return
     */
    MediaFFMPEGImpl& operator=(const MediaFFMPEGImpl& t_instance) noexcept;
    /**
     *
     * @param t_instance
     * @return
     */
    MediaFFMPEGImpl& operator=(MediaFFMPEGImpl&& t_instance) noexcept;

   public:
    auto initializeMedia() -> media_error_t;
    auto startMediaplayback(std::string& t_sourcepath)->media_error_t;
    auto playMedia() -> media_error_t;
    auto pauseMedia() -> media_error_t;
    auto seekMedia() -> media_error_t;
    auto fastForwardMedia() -> media_error_t;
    auto fastReverseMedia() -> media_error_t;



   private:
    auto isStreamingMedia(std::string& t_urlsrc)->boolean_t;
    auto startStreaming()->media_error_t;
    auto demuxStream()->media_error_t;
    auto decodeStream()->media_error_t;
    auto filterStream()->media_error_t;
    auto convertOutptStream()->media_error_t;

   private:
    /**
     * @brief: structure for having stream property like decoder, buffer, stream index etc.
     */
    using stream_property_t=struct stream_property_t{
         std::string urlsrc;
         AVFormatContext* formatcntx;
    };

   private:
    /**
     * @details: instance of actual stream having properties like decoder,buf etc.
     */
    stream_property_t m_Stream;
};

}  // namespace ffmpeg
}  // namespace media

#endif /* MEDIAFFMPEG_SRC_MEDIAFFMPEGIMPL_H_ */
