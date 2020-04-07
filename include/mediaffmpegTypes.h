/*************************************************************************************
 * @name     :    mediaffmpegTypes.h
 *
 * @brief    :    All datatypes to be exposed to client
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

#ifndef MEDIAFFMPEG_INCLUDE_MEDIAFFMPEGTYPES_H_
#define MEDIAFFMPEG_INCLUDE_MEDIAFFMPEGTYPES_H_
#include <iostream>
#include<memory>

namespace media {
namespace ffmpeg {

enum class media_error_t { MEDIA_GENERIC_ERROR,MEDIA_NO_ERROR };

enum class boolean_t { FALSE, TRUE };
}  // namespace ffmpeg
}  // namespace media

#endif /* MEDIAFFMPEG_INCLUDE_MEDIAFFMPEGTYPES_H_ */
