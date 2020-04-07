/*
 * maintest.cpp
 *
 *  Created on: 03-Apr-2020
 *      Author: ashish
 */

#include <iostream>
#include "../include/mediaffmpegclient.h"

namespace mffpeg = media::ffmpeg;
int main(int argv, char **argc) {

    auto choice = 0;

    mffpeg::MediaFFMPEGClient mClient;
    std::string sourcepath = "";
    do {

        std::cout << "\n\n1. <-Play->\n2. <-Pause->\n3. <-Next->\n4. <-Previous->\n5. <-Seek->\n6. "
                     "<-FastForward->\n7. <-FastReverse->\n8. <-EXIT->\n Enter the choice: \n";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cerr << "INVALID choice.. Please Enter valid choice\n\n";
            continue;
        }

        switch (choice) {
            case 1: {
                // TODO: Play
            	std::cout<<"Enter the source url\n";
            	std::cin.ignore();
            	std::getline(std::cin,sourcepath);
                mClient.playMedia(sourcepath);
            } break;
            case 2: {
                // TODO: Pause
                mClient.pauseMedia();
            } break;
            case 3: {
                // TODO: Next
                mClient.nextMedia();
            } break;
            case 4: {
                // TODO: Previous
                mClient.previousMedia();
            } break;
            case 5: {
                // TODO: Seek
                mClient.seekMedia();
            } break;
            case 6: {
                // TODO: FastForward
                mClient.fastForwardMedia();

            } break;
            case 7: {
                // TODO: FastReverse
                mClient.fastReverseMedia();
            } break;
            case 8: {
                // TODO: EXIT
                exit(0);
            } break;
            default: { std::cout << "Invalid choice....Please Enter valid choice\n"; } break;
        }

    } while (1);

    return 0;
}
