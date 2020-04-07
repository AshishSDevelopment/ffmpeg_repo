/*
 * mediaFFMPEGimpl.cpp
 *
 *  Created on: 03-Apr-2020
 *      Author: ashish
 */
#include "mediaffmpegimpl.h"
namespace media {
namespace ffmpeg {

MediaFFMPEGImpl::MediaFFMPEGImpl() noexcept:m_Stream{"",nullptr} { std::cout << "Enter in MediaFFMPEGImpl::constr\n"; }

MediaFFMPEGImpl::~MediaFFMPEGImpl() noexcept { std::cout << "Enter in MediaFFMPEGImpl::destr\n"; }

MediaFFMPEGImpl::MediaFFMPEGImpl(const MediaFFMPEGImpl& t_instance) noexcept {
    std::cout << "Enter in MediaFFMPEGImpl::copy constr\n";
}

MediaFFMPEGImpl::MediaFFMPEGImpl(MediaFFMPEGImpl&& t_instance) noexcept {
    std::cout << "Enter in MediaFFMPEGImpl::move constr\n";
}

MediaFFMPEGImpl& MediaFFMPEGImpl::operator=(const MediaFFMPEGImpl& t_instance) noexcept {
    std::cout << "Enter in MediaFFMPEGImpl::copy assign operator\n";

    return (*this);
}

MediaFFMPEGImpl& MediaFFMPEGImpl::operator=(MediaFFMPEGImpl&& t_instance) noexcept {
    std::cout << "Enter in MediaFFMPEGImpl::move assign operator\n";
    return (*this);
}

auto MediaFFMPEGImpl::initializeMedia() -> media_error_t {
    std::cout << "Enter in MediaFFMPEGImpl::initializeMedia\n";
    return ffmpeg::media_error_t::MEDIA_NO_ERROR;

}

auto MediaFFMPEGImpl::startMediaplayback(std::string& t_sourcepath)->media_error_t{
	std::cout<<"Enter in startMediaplayback\n";
	if(isStreamingMedia(t_sourcepath)==boolean_t::FALSE){
		std::cout<<"New url source\n";
		m_Stream.urlsrc=t_sourcepath;
		if(avformat_open_input(&m_Stream.formatcntx,t_sourcepath.c_str(),nullptr,nullptr)<0){
			std::cerr<<"Format open error\n";
			return ffmpeg::media_error_t::MEDIA_GENERIC_ERROR;
		}

		 if (avformat_find_stream_info(m_Stream.formatcntx, nullptr) < 0) {
		       std::cerr<<"error to find stream info\n";
		       return ffmpeg::media_error_t::MEDIA_GENERIC_ERROR;
		    }
	}
	else{
		std::cout<<"already streaing media\n";
		playMedia();
	}
	 return media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGImpl::playMedia() -> media_error_t {
    std::cout << "Enter in MediaFFMPEGImpl::playMedia\n";
    return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGImpl::pauseMedia() -> media_error_t {
    std::cout << "Enter in MediaFFMPEGImpl::pauseMedia\n";
    return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGImpl::seekMedia() -> media_error_t {
    std::cout << "Enter in MediaFFMPEGImpl::seekMedia\n";
    return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGImpl::fastForwardMedia() -> media_error_t {
    std::cout << "Enter in MediaFFMPEGImpl::fastForwardMedia\n";
    return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGImpl::fastReverseMedia() -> media_error_t {
    std::cout << "Enter in MediaFFMPEGImpl::fastReverseMedia\n";
    return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGImpl::isStreamingMedia(std::string& t_urlsrc)->boolean_t{
     std::cout<<"Enter in MediaFFMPEGImpl::isPlayingMedia\n";
     //TODO:check some other always for accuracy
	return (t_urlsrc!=m_Stream.urlsrc?boolean_t::FALSE:boolean_t::TRUE);
}
auto MediaFFMPEGImpl::startStreaming()->media_error_t{
	std::cout<<"Enter in MediaFFMPEGImpl::startStreaming\n";
	return media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGImpl::demuxStream()->media_error_t{
	std::cout<<"Enter in MediaFFMPEGImpl::demuxStream\n";
	return media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGImpl::decodeStream()->media_error_t{
	std::cout<<"Enter in MediaFFMPEGImpl::decodeStream\n";
	return media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGImpl::filterStream()->media_error_t{
	std::cout<<"Enter in MediaFFMPEGImpl::filterStream\n";
	return media_error_t::MEDIA_NO_ERROR;
}
auto MediaFFMPEGImpl::convertOutptStream()->media_error_t{
	std::cout<<"Enter in MediaFFMPEGImpl::convertOutptStream\n";
	return media_error_t::MEDIA_NO_ERROR;
}
}  // namespace ffmpeg
}  // namespace media
