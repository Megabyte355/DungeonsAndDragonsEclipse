/*
 * AudioManager.h
 *
 *      Author: tim
 */

#ifndef AUDIOMANAGER_H_
#define AUDIOMANAGER_H_

#include "SDL_mixer.h"
#include "SDL.h"
#include <map>
#include <string>


//Mix_PlayChannel
//Mix_PausedMusic
//Mix_HaltMusic
//Mix_PlayMusic
//scratch = Mix_LoadWAV( "scratch.wav" );

class AudioManager
{
    public:

        static AudioManager * getInstance();

        Mix_Music *music;
        Mix_Chunk *sfx;
      //  std::map Soundmap pair<>
        //std::map<Mix_Music, int> musicMap;
//        std::map<Mix_Chunk, int> soundMap;

        int song;
        void load_files();
        void clean_up();
        void init();
        void run();
        void playMusic(int);
        void playSound(int);
        void stop();

    private:
        ~AudioManager();
        AudioManager();
        static AudioManager * instance;
};

#endif /* AUDIOMANAGER_H_ */
