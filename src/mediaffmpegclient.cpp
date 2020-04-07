/*
 * mediaFFMPEGclient.cpp
 *
 *  Created on: 03-Apr-2020
 *      Author: ashish
 */

#include "../include/mediaffmpegclient.h"
namespace media {
namespace ffmpeg {

MediaFFMPEGClient::MediaFFMPEGClient() noexcept:m_mediaUniPtr(std::make_unique<MediaFFMPEGImpl>()) {
    std::cout << "enter MediaFFMPEGClient::constructor\n";
}

MediaFFMPEGClient::~MediaFFMPEGClient() noexcept {
    std::cout << "enter MediaFFMPEGClient::destructor\n";
}

MediaFFMPEGClient::MediaFFMPEGClient(const MediaFFMPEGClient& t_instance) noexcept {
    std::cout << "enter MediaFFMPEGClient::copy constr\n";
}

MediaFFMPEGClient::MediaFFMPEGClient(MediaFFMPEGClient&& t_instance) noexcept {
    std::cout << "enter MediaFFMPEGClient::move constr\n";
}

MediaFFMPEGClient& MediaFFMPEGClient::operator=(const MediaFFMPEGClient& t_instance) noexcept {
    std::cout << "enter MediaFFMPEGClient::copy assign operator\n";
    return (*this);
}

MediaFFMPEGClient& MediaFFMPEGClient::operator=(MediaFFMPEGClient&& t_instance) noexcept {
    std::cout << "enter MediaFFMPEGClient::move assign operator\n";
    return (*this);
}

auto MediaFFMPEGClient::initializeMedia() -> media_error_t {
    std::cout << "enter MediaFFMPEGClient:: initializemedia\n";
    if(m_mediaUniPtr){
    	m_mediaUniPtr->initializeMedia();
    }
   return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGClient::playMedia(std::string& t_sourcepath) -> media_error_t {
    std::cout << "enter MediaFFMPEGClient:: playmedia\n";
    if(m_mediaUniPtr){
    	return m_mediaUniPtr->startMediaplayback(t_sourcepath);
    }
    return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGClient::pauseMedia() -> media_error_t {
    std::cout << "enter MediaFFMPEGClient:: pausemedia\n";
    if(m_mediaUniPtr){
    	m_mediaUniPtr->pauseMedia();
    }
    return media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGClient::nextMedia() -> media_error_t {
    std::cout << "enter MediaFFMPEGClient:: nextmedia\n";
    return ffmpeg::media_error_t::MEDIA_NO_ERROR;

}
auto MediaFFMPEGClient::previousMedia() -> media_error_t {
    std::cout << "enter MediaFFMPEGClient:: previousmedia\n";
    return ffmpeg::media_error_t::MEDIA_NO_ERROR;

}
auto MediaFFMPEGClient::seekMedia() -> media_error_t {
    std::cout << "enter MediaFFMPEGClient:: seekmedia\n";
    if(m_mediaUniPtr){
    	m_mediaUniPtr->seekMedia();
    }
    return media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGClient::fastForwardMedia() -> media_error_t {
    std::cout << "enter MediaFFMPEGClient::fastForwardmedia\n";
    if(m_mediaUniPtr){
    	m_mediaUniPtr->fastForwardMedia();
    }
    return media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGClient::fastReverseMedia() -> media_error_t {
    std::cout << "enter MediaFFMPEGClient:: fastreversemedia\n";
    if(m_mediaUniPtr){
    	m_mediaUniPtr->fastReverseMedia();
    }
    return media_error_t::MEDIA_NO_ERROR;
}
}  // namespace ffmpeg
}  // namespace media
