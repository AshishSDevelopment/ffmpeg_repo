/*
 * main.cpp
 *
 *  Created on: 03-Apr-2020
 *      Author: ashish
 */

#ifndef MEDIAFFMPEG_SKIPE_MAIN_CPP_
#define MEDIAFFMPEG_SKIPE_MAIN_CPP_

#include "player.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

#undef main  // preventing that SDL has any conflicts with main()

namespace test = media::test;

int main(int argc, char *argv[]) {
    //    startAudioPlayer(argc > 1 ? argv[1] : "jonas.mp3", 250);
    auto choice = 0;
    std::cout << "\n\n******************** AUDIO PLAYER ************************\n\n";
    test::Player mPlayer;
    if (argc != 2) {
        std::cout << "Usage:  provide source name\n";
        exit(1);
    }
    std::string s(argv[1]);
    mPlayer.initiaizeMedia();
    mPlayer.startPlayback(s, 250);
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
                mPlayer.playMedia();
            } break;
            case 2: {
                // TODO: Pause
                mPlayer.pauseMedia();
            } break;
            case 3: {
                // TODO: Next

            } break;
            case 4: {
                // TODO: Previous

            } break;
            case 5: {
                // TODO: Seek
                mPlayer.seekMedia();
            } break;
            case 6: {
                // TODO: FastForward
                mPlayer.fastForwardMedia();

            } break;
            case 7: {
                // TODO: FastReverse
                mPlayer.fastReverseMedia();
            } break;
            case 8: {
                // TODO: EXIT
                exit(0);
            } break;
            default: { std::cout << "Invalid choice....Please Enter valid choice\n"; } break;
        }

    } while (1);
    mPlayer.stopMedia();

    return 0;
}

#endif /* MEDIAFFMPEG_SKIPE_MAIN_CPP_ */
