# mediaFFMPEG

**** Installation from source code FFMPEG*****************

1. Download from  https://www.ffmpeg.org/download.html or clone code  from git clone https://git.ffmpeg.org/ffmpeg.git ffmpeg

2. configure with proper flag set.
  1../configure --prefix=/usr       #if you want to install prefix as /usr or by default /usr/local
  2../configure --prefix=/usr --enable-shared #if you compile library as shared.by default static libraries
  3../configure --prefix=/usr --enable-shared --enable-gnutls         #openssl, TSL, https

You can use :
  [--prefix=/usr --extra-version=0ubuntu0.18.04.1 --toolchain=hardened --libdir=/usr/lib/x86_64-linux-gnu --incdir=/usr/include/x86_64-linux-gnu --enable-gpl --disable-stripping --enable-avresample --enable-avisynth --enable-gnutls --enable-ladspa --enable-libass --enable-libbluray --enable-libbs2b --enable-libcaca --enable-libcdio --enable-libflite --enable-libfontconfig --enable-libfreetype --enable-libfribidi --enable-libgme --enable-libgsm --enable-libmp3lame --enable-libmysofa --enable-libopenjpeg --enable-libopenmpt --enable-libopus --enable-libpulse --enable-librubberband --enable-librsvg --enable-libshine --enable-libsnappy --enable-libsoxr --enable-libspeex --enable-libssh --enable-libtheora --enable-libtwolame --enable-libvorbis --enable-libvpx --enable-libwavpack --enable-libwebp --enable-libx265 --enable-libxml2 --enable-libxvid --enable-libzmq --enable-libzvbi --enable-omx --enable-openal --enable-opengl --enable-sdl2 --enable-libdc1394 --enable-libdrm --enable-libiec61883 --enable-chromaprint --enable-frei0r --enable-libopencv --enable-libx264 --enable-shared]



  
3. compile
  1. make   # if root permission  
  2. sudo make install # grant root permission
 
4. Install
   1. make install                     #if root permission
   2. sudo make install                # grant root permission
   
   
   
**** Installation linux terminal***************** 

1.sudo apt install ffmpeg libavcodec-dev libavfilter-dev libavformat-dev libavdevice-dev libavutil-dev libavresample-dev  libpostproc-dev libsdl2-2.0-0 libswresample-dev libswscale-dev  



CMakelists.txt: 

1. Include: (require FindFFmpeg.cmake to respective cmake module path) 
  a. find_package(FFmpeg REQUIRED)
  b. include_directories(${FFMPEG_INCLUDE_DIR})
  c. include library with  ${FFMPEG_LIBRARIES}

    



step to use:

1. you can use reference code from reference folder as audioplayer
  1. cd build
  2. rm -rf *
  3. cmake ../
  4. make
  5. ./mediatest /home/ashish/songs/songname.mp3

2. You can run code from skip as well as player

 1. cd build 
 2. rm -rf *
 3. cmake ../
 4. make 
 5. ./mediatest {path to song}

Note: This code is under development

3. You can run code from src folder as mediaffmpeg

 1. cd build
 2. rm -rf *
 3. cmake ../
 4. make
 5. ./mediatest

Note: this code is under develeopment this is actual implementation and skipe is for testing   
