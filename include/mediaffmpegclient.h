/*************************************************************************************
 * @name     :    mediaffmpegclient.h
 *
 * @brief    :    media ffmpeg API for client
 *
 * @author   :    KPIT Technologies Ltd.
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

#ifndef MEDIAFFMPEG_INCLUDE_MEDIAFFMPEGCLIENT_H_
#define MEDIAFFMPEG_INCLUDE_MEDIAFFMPEGCLIENT_H_

#include "mediaffmpegTypes.h"
#include "../src/mediaffmpegimpl.h"
/**
 *
 */
namespace media {
namespace ffmpeg {

/**
 *
 */
class MediaFFMPEGClient final {
   public:
    /**
     *
     */
    MediaFFMPEGClient() noexcept;
    /**
     *
     */
    ~MediaFFMPEGClient() noexcept;
    /**
     *
     * @param t_instance
     */
    MediaFFMPEGClient(const MediaFFMPEGClient& t_instance) noexcept;
    /**
     *
     * @param t_instance
     */
    MediaFFMPEGClient(MediaFFMPEGClient&& t_instance) noexcept;
    /**
     *
     * @param t_instance
     * @return
     */
    MediaFFMPEGClient& operator=(const MediaFFMPEGClient& t_instance) noexcept;
    /**
     *
     * @param t_instance
     * @return
     */
    MediaFFMPEGClient& operator=(MediaFFMPEGClient&& t_instance) noexcept;

   public:
    auto initializeMedia() -> media_error_t;
    auto playMedia(std::string& t_sourcepath) -> media_error_t;
    auto pauseMedia() -> media_error_t;
    auto nextMedia() -> media_error_t;
    auto previousMedia() -> media_error_t;
    auto seekMedia() -> media_error_t;
    auto fastForwardMedia() -> media_error_t;
    auto fastReverseMedia() -> media_error_t;

    private:

   std::unique_ptr<MediaFFMPEGImpl> m_mediaUniPtr;
};

}  // namespace ffmpeg
}  // namespace media

#endif /* MEDIAFFMPEG_INCLUDE_MEDIAFFMPEGCLIENT_H_ */
