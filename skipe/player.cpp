/*
 * player.cpp
 *
 *  Created on: 03-Apr-2020
 *      Author: ashish
 */
#include "player.h"
extern "C"
{
#include <libavutil/avstring.h>
#include <libavutil/pixdesc.h>
#include <libavformat/avformat.h>
#include <libavdevice/avdevice.h>
#include <libswscale/swscale.h>
#include<libavcodec/avcodec.h>
#include <libavcodec/avfft.h>
#include <libavfilter/avfilter.h>

}
static int64_t duration = AV_NOPTS_VALUE;
static int64_t start_time = 0;
namespace media {
namespace test {

Player::Player():m_StreamState{ffmpeg::boolean_t::FALSE,ffmpeg::boolean_t::FALSE,ffmpeg::boolean_t::FALSE,0,0,"",nullptr,{-1,-1,-1},nullptr,0,0,nullptr,0,0},m_streamPacketQueue(new StreamPacketQueue()){ std::cout << "enter in Player::constr\n"; }
Player::~Player() { std::cout << "enter in Player::destrctr\n"; }
Player::Player(const Player& t_instance) { std::cout << "enter in Player::copy cnstr\n"; }
Player::Player(Player&& t_instance) { std::cout << "enter in Player::move cnstr\n"; }
Player& Player::operator=(const Player& t_instance) {
    std::cout << "enter in Player::copy assign operator\n";

    return (*this);
}
Player& Player::operator=(Player&& t_instance) {
    std::cout << "enter in Player::move assign operator\n";

    return (*this);
}
auto Player::startPlayback(std::string& sourcename, int bufferSize) -> ffmpeg::media_error_t {

	  std::cout<<"Enter in Player::startplayback: source name: ["<<sourcename<<"]\n";

    AVInputFormat *fmt=nullptr;
    AVDictionary *options=nullptr;

    /**
     * check the valid source name as mp3, mp4 or any media type
     * otherwise return as error
     * 1. call av_allocate_context() for Avformatcontext
     * 2. call av_dict_copy() --> av_dict_get(),av_dict_copy-->av_dict_set()
     * 3. av_dict_get() // this function is imp. when use to get metadata
     * 4. av_opt_set_dict()--> av_opt_set_dict2()-->av_dict_free()
     * 5. init_input() for avformatcontext further call probe methods
     */
	if(avformat_open_input(&m_StreamState.m_formatCntx,sourcename.c_str(),fmt,&options)<0){
		std::cerr<<"Format open error\n";
		return ffmpeg::media_error_t::MEDIA_GENERIC_ERROR;
	}

	 if (avformat_find_stream_info(m_StreamState.m_formatCntx, NULL) < 0) {
	       std::cerr<<"error to find stream info\n";
	       return ffmpeg::media_error_t::MEDIA_GENERIC_ERROR;
	    }


        m_StreamState.filename=sourcename;

        m_StreamState.parse_tid = SDL_CreateThread(decodeStream,this);


    return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
auto Player::initiaizeMedia() -> ffmpeg::media_error_t {

	std::cout<<"Enter in Player::initiaizeMedia\n";
    // set log flages
    av_log_set_flags(AV_LOG_SKIP_REPEATED);
    /**
     * @details:Initialize libavdevice and register all the input and output devices.
     *          avdevice_register_all()-->register_all(void)-->
                REGISTER_OUTDEV(X, x) or REGISTER_INDEV(X, x)
                        |                      |
                        |                      |
            av_register_output_format()   av_register_input_format()
     *
     *
     */
    avdevice_register_all();
    // network protocol
    avformat_network_init();


    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) {
        std::cerr<<"Error: SDL could not be initialized:"<<SDL_GetError()<<"\n";
        return ffmpeg::media_error_t::MEDIA_GENERIC_ERROR;
    }
    SDL_EventState(SDL_SYSWMEVENT, SDL_IGNORE);
    SDL_EventState(SDL_USEREVENT, SDL_IGNORE);
    flushPacket=m_streamPacketQueue->getFLushPacket();
    av_init_packet(flushPacket);
    flushPacket->data = (uint8_t *)flushPacket;

    return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
auto Player::playMedia() -> ffmpeg::media_error_t { std::cout << "enter in Player::playMedia\n";
return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
auto Player::pauseMedia() -> ffmpeg::media_error_t { std::cout << "enter in Player::pauseMedia\n";
return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
auto Player::seekMedia() -> ffmpeg::media_error_t { std::cout << "enter in Player::seekMedia\n";
return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
auto Player::fastForwardMedia() -> ffmpeg::media_error_t {
    std::cout << "enter in Player::fastForwardMedia\n";
    return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
auto Player::fastReverseMedia() -> ffmpeg::media_error_t {
    std::cout << "enter in Player::fastReverseMedia\n";
    return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}
auto Player::stopMedia() -> ffmpeg::media_error_t { std::cout << "enter in Player::stopMedia\n";
return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}

ffmpeg::media_error_t Player::getMetadata(metadata_t& t_instance){
	std::cout<<"enter in Player::getmetadata\n";
	if(m_StreamState.m_formatCntx){
      t_instance.filename=std::string(m_StreamState.m_formatCntx->filename);
      t_instance.duration=(uint64_t)(m_StreamState.m_formatCntx->duration);
      auto dict = av_dict_get(m_StreamState.m_formatCntx->metadata, "title", NULL, 0);
      if (dict) {
          t_instance.title=std::string(dict->value);
          dict=nullptr;
      }
      else{
          auto firstPos=t_instance.filename.find_last_of('/');
          auto lastPos=t_instance.filename.find_last_of('.');
          t_instance.title=t_instance.filename.substr(firstPos+1,lastPos-firstPos-1);
      }

      dict = av_dict_get(m_StreamState.m_formatCntx->metadata, "album", nullptr, 0);
      if (dict) {
                t_instance.album=std::string(dict->value);
                dict=nullptr;
            }

      dict = av_dict_get(m_StreamState.m_formatCntx->metadata, "artist", nullptr, 0);
      if (dict) {
                t_instance.artist=std::string(dict->value);
                dict=nullptr;
            }
	}
	return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}


ffmpeg::media_error_t Player::getStreamInfo(){
	std::cout<<"enter in Player::getStreamInfo\n";
    for (auto i = 0; i < m_StreamState.m_formatCntx->nb_streams; i++) {
        if (m_StreamState.m_formatCntx->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO) {
            m_StreamState.m_StreamIndex[STREAM_INDEX_AUDIO] = i;
        }
        else if(m_StreamState.m_formatCntx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO){
        	m_StreamState.m_StreamIndex[STREAM_INDEX_VIDEO] = i;
        }
        else if(m_StreamState.m_formatCntx->streams[i]->codec->codec_type == AVMEDIA_TYPE_SUBTITLE){
        	m_StreamState.m_StreamIndex[STREAM_INDEX_SUBTITLE]=i;
        }
    }
	return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}

int decodeStream(void* t_instance){
	Player *player=(Player*)t_instance;
	AVPacket pkt1,*pkt=&pkt1;
	int eof=0;
	int ret=0;
	int pkt_in_play_range = 0;
  std::cout<<"enter in Player::decodestream \n";
	 //get the audio stream index

  if(player->m_StreamState.m_formatCntx->pb)
	  player->m_StreamState.m_formatCntx->pb->eof_reached=0;

      player->getStreamInfo();
      if(player->m_StreamState.m_StreamIndex[STREAM_INDEX_AUDIO]>=0){

       metadata_t meta{"","UNKNOWN ALBUM","UNKNOWN ARTIST",0,"",""};
       player->getMetadata(meta);

       std::cout<<"                    TITLE: "<<meta.title<<"                    \n";
       std::cout<<"                    ALBUM: "<<meta.album<<"                    \n";
       std::cout<<"                   ARTIST: "<<meta.artist<<"                   \n";
       std::cout<<"                 DURATION: "<<meta.duration<<"                 \n";
       player->streamComponentOpen(player->m_StreamState.m_StreamIndex[STREAM_INDEX_AUDIO]);
      }
      else{
   	   std::cerr<<"No audio stream found\n";
   	  return -1;
      }


      while(1){
          if(player->m_StreamState.abort_request==ffmpeg::boolean_t::TRUE){
        	  std::cout<<"stop streaming request\n";
        	  break;
          }
          if(player->m_StreamState.paused==ffmpeg::boolean_t::TRUE){
        	  av_read_pause(player->m_StreamState.m_formatCntx);
          }
          else{
        	  av_read_play(player->m_StreamState.m_formatCntx);
          }
          if(player->m_StreamState.seekRequest==ffmpeg::boolean_t::TRUE){
        	  int64_t seek_target= player->m_StreamState.seekPos;
        	  int64_t seek_min= player->m_StreamState.seekRel > 0 ? seek_target - player->m_StreamState.seekRel + 2: INT64_MIN;
        	  int64_t seek_max= player->m_StreamState.seekRel < 0 ? seek_target - player->m_StreamState.seekRel - 2: INT64_MAX;

        	  if(avformat_seek_file(player->m_StreamState.m_formatCntx, -1, seek_min, seek_target, seek_max, ~AVSEEK_FLAG_BYTE)<0){
                std::cerr<<"Error while seeking stream\n";
        	  }
        	  else{
        		  if(player->m_StreamState.m_StreamIndex[STREAM_INDEX_AUDIO]>=0){
        			  player->m_streamPacketQueue->packetQueueFlush();
        			  player->m_streamPacketQueue->packetQueuePut(player->flushPacket);
        		  }
        	  }
        	  player->m_StreamState.seekRequest = ffmpeg::boolean_t::FALSE;
        	  eof=0;
          }
          if(avio_feof(player->m_StreamState.m_formatCntx->pb) || eof) {
        	  //todo::
        	  SDL_Delay(10);
        	  continue;
          }

          ret=av_read_frame(player->m_StreamState.m_formatCntx, pkt);
          if(ret<0){
              if(ret==AVERROR_EOF){
            	  eof=1;

              }
              SDL_Delay(100); //wait for user events
          }
          pkt_in_play_range=duration == AV_NOPTS_VALUE ||(pkt->pts - player->m_StreamState.m_formatCntx->streams[pkt->stream_index]->start_time) *
        		                        av_q2d(player->m_StreamState.m_formatCntx->streams[pkt->stream_index]->time_base) -(double)(start_time != AV_NOPTS_VALUE ? start_time : 0)/1000000
										<= ((double)duration/1000000);
          if (pkt->stream_index == player->m_StreamState.m_StreamIndex[STREAM_INDEX_AUDIO]&& pkt_in_play_range) {
                    player->m_streamPacketQueue->packetQueuePut(pkt);
            }
          else {
                av_free_packet(pkt);
            }


      }




	return 1;
}

ffmpeg::media_error_t Player::streamComponentOpen(int t_index){
    AVCodecContext *avctx=nullptr;
    AVCodec *codec=nullptr;
    SDL_AudioSpec wanted_spec, spec;

    if(t_index < 0 || t_index >= m_StreamState.m_formatCntx->nb_streams){
    	std::cerr<<"Error Invalid stream index\n";
    	return ffmpeg::media_error_t::MEDIA_GENERIC_ERROR;
    }
  avctx=m_StreamState.m_formatCntx->streams[t_index]->codec;

  if(avctx->codec_type==AVMEDIA_TYPE_AUDIO){
    if(avctx->channels>0){
    	avctx->request_channel_layout = FFMIN(2, avctx->channels);
    }else{
    	avctx->request_channel_layout = 2;
    }

  }


  codec=avcodec_find_decoder(avctx->codec_id);
  //avcodec_thread_init(avctx, 1);
  //set_context_opts(avctx, avcodec_opts[avctx->codec_type], 0);


  if (avctx->codec_type == AVMEDIA_TYPE_AUDIO) {
wanted_spec.freq = avctx->sample_rate;
 wanted_spec.format = AUDIO_S16SYS;
 wanted_spec.channels = avctx->channels;
 wanted_spec.silence = 0;
 wanted_spec.samples = 32768; //TODO may be change
 wanted_spec.callback = AudioCallback;
   wanted_spec.userdata = this;
   if (SDL_OpenAudio(&wanted_spec, &spec) < 0) {
     std::cerr<<"SDL_OpenAudio: "<< SDL_GetError()<<"\n";
     return ffmpeg::media_error_t::MEDIA_GENERIC_ERROR;
  }
   m_StreamState.audioHwBufSize = spec.size;
  m_StreamState.audioSrcFormat= AV_SAMPLE_FMT_S16;
  if(avctx->codec_type==AVMEDIA_TYPE_AUDIO){
	  m_StreamState.avstream = m_StreamState.m_formatCntx->streams[m_StreamState.m_StreamIndex[STREAM_INDEX_AUDIO]];
	 m_StreamState.audioBufSize = 0;
	  m_StreamState.audioBufIndex = 0;
	  m_streamPacketQueue->packetQueueInit();
      SDL_PauseAudio(0);
  }

}

	return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}


void AudioCallback(void *data, uint8_t *stream, int streamLength){
 std::cout<<"enter in audiocallback with stream length : "<<streamLength<<"\n";
 Player *player=(Player*)(data);

 //while(streamLength>0){
//	 if ( player->m_StreamState.audioBufIndex>= player->m_StreamState.audioBufSize){
//		 std::cout<<"Enter in if stmstate->audioBufIndex>= stmstate->audioBufSize\n";
//    player->audioFrameDecode(nullptr);
//	 }
//	 else{
//        std::cout<<"Enter in else stmstate->audioBufIndex>= stmstate->audioBufSize\n";
//	 }
 //}
}

ffmpeg::media_error_t Player::streamComponentClose(int t_index){


	 return ffmpeg::media_error_t::MEDIA_NO_ERROR;
}


int Player::audioFrameDecode(double *pts_ptr){
	 AVPacket *pkt_temp =&m_StreamState.audioPktTemp;
	AVPacket *pkt = &m_StreamState.audioPkt;
	AVCodecContext *dec= m_StreamState.avstream->codec;
	int n, len1, data_size;
	double pts;

	while(1){
		do {
			std::cout<<"while loop pkt_temp->size > 0\n ";

			len1 = avcodec_decode_audio4(dec,
			 (AVFrame *)m_StreamState.audio_buf1, &data_size, pkt_temp);

		}while (pkt_temp->size > 0);
	}
}
}  // namespace test
}  // namespace media
