/*
 * AudioManager.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: Tim
 */


#include "AudioManager.h"
#include <iostream>

AudioManager* AudioManager::instance = nullptr;


AudioManager::AudioManager(){
    music = nullptr;
    sfx = nullptr;
}

AudioManager::~AudioManager(){}

void AudioManager::init(){
   //Initialize SDL_mixer
	if(Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
	{
		std::cout<<"audio initiated";
	}
	song = 0;
}

AudioManager * AudioManager::getInstance(){
	if (instance == nullptr) {
			instance = new AudioManager();
			instance->init();

	}
    return instance;
}

void AudioManager::load_files(){

//    music = Mix_LoadMUS( "assets/beat.wav" );
//    if( music == NULL )
//      {
//      }
}

void AudioManager::playMusic(int i){

	bool dontplay;
	if(song==i){
		dontplay = true;
	}
	else{
		Mix_FreeMusic(music);
		//clean_up();
		//init();
	}


	switch(i){
		case 1:
			if(song!=1)
				music = Mix_LoadMUS("assets/title.wav");
			song = 1;
			break;
		case 2:
			if(song!=2)
				music = Mix_LoadMUS("assets/menu.wav");
			song=2;
			break;
		default:
			music = NULL;
			break;
	}

	if(music!=NULL&&!dontplay)
        int i = Mix_PlayMusic( music, -1 );

}

void AudioManager::playSound(int i){
	Mix_FreeChunk(sfx);
	switch(i){
	case 1://menu hover
		sfx = Mix_LoadWAV("assets/menuhover.wav");
		break;
	case 2://menu click
		sfx = Mix_LoadWAV("assets/menuclick.wav");
		break;
	case 3://sword attack
		sfx = Mix_LoadWAV("assets/weaponAttack.wav");
		break;
	case 4://bow attack
		sfx = Mix_LoadWAV("assets/arrowAttack.wav");
		break;
	case 5://fanfare
		sfx = Mix_LoadWAV("assets/fanfare.wav");
		break;
	case 6:
		sfx = Mix_LoadWAV("assets/menuclick.wav");
		break;
	case 7:
		sfx = Mix_LoadWAV("assets/menuclick.wav");
		break;
	default:
		sfx = NULL;
		break;

	}

	int s = Mix_PlayChannel(1, sfx, 0);
}

void AudioManager::clean_up(){
	    //Free the music
	//    Mix_FreeMusic( music );

	 //   Mix_FreeChunk( med );
	    //Quit SDL_mixer
	    Mix_CloseAudio();
}
void AudioManager::run(){


}
