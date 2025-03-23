#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "../music.h"
#pragma execution_character_set("utf-8")
extern std::string Task;
std::vector<std::string> Tasks;
extern std::vector<TTF_Font*> Fonts;
extern bool ldfail;
extern int errtyp;
extern std::string cfgph;
extern std::vector<SDL_Surface*> Imgs;
extern int drtxmd;
extern float testvar;
extern int ROOM;
extern std::vector<Sounds>wavfiles;
extern SDL_AudioStream* stream;
extern std::vector<std::vector<std::string>> roomscripts;
extern SDL_Window* window;
SDL_AudioSpec spec;
int LoadGame(void* data) {
	SDL_Log("\033[36mE'd Grami Engine Powered by LibSDL\33[0m");
	Task = "Loading ./Data/boot.sbhsj";
	std::fstream tasks("./Data/boot.sbhsj",std::ios::in);
	std::string line;
	std::string WavPath = "";
	while (std::getline(tasks, line)) {
		Tasks.push_back(line);
	}
	for (int i = 0; i < Tasks.size(); i++)
	{
		Task = Tasks[i];
		std::vector<std::string> vstr;
		boost::split(vstr, Task, boost::is_any_of(" "), boost::token_compress_on);
		SDL_Log(Tasks[i].c_str());
		if (vstr[0] == "LoadFont") {
			TTF_Font* font = TTF_OpenFont(vstr[1].c_str(), atoi(vstr[2].c_str()));
			if (!font)
			{
				std::string errm(SDL_GetError());
				Task = "Error!" + errm;
				SDL_Log(Task.c_str());
				ldfail = true;
				errtyp = 1;
				return 1;
			}
			Fonts.push_back(font);
		}
		else if (vstr[0] == "LoadImg") {
			SDL_Surface* temp = IMG_Load(vstr[1].c_str());
			if (!temp) {
				std::string errm(SDL_GetError());
				Task = "Error!" + errm;
				SDL_Log(Task.c_str());
				ldfail = true;
				errtyp = 1;
				return 1;
			}
			Imgs.push_back(temp);
		}
		else if (vstr[0] == "LoadCfg") {
			cfgph = vstr[1];
			std::fstream cfg(vstr[1], std::ios::in);
			char sb[200];
			int shushu = 0;
			while (cfg.good()) {
				cfg >> sb;
				if (shushu == 0)
					drtxmd = atoi(sb);
				if (shushu == 1)
					testvar = atoi(sb);
				SDL_Log(sb);
				shushu++;
			}
			cfg.close();
		}
		else if (vstr[0] == "ChangeRoomTo1") {
			ROOM = 1;
		}
		else if (vstr[0] == "SetWavPath") {
			WavPath = vstr[1];
		}
		else if (vstr[0] == "LoadWav") {
			char* dfhdu_path = NULL;
			SDL_asprintf(&dfhdu_path, ("%s"+vstr[1]).c_str(), SDL_GetBasePath());
			
			Sounds Snds = { NULL,0 };
			if (!SDL_LoadWAV(dfhdu_path,&spec,&Snds.wav_data,&Snds.wav_data_len)) {
				SDL_Log("Couldn't load .wav file: %s", SDL_GetError());
				std::string errm(SDL_GetError());
				Task = "Error!" + errm;
				SDL_Log(Task.c_str());
				ldfail = true;
				errtyp = 1;
				return 1;
			}
			SDL_free(dfhdu_path);
			wavfiles.push_back(Snds);
		}
		else if (vstr[0] == "LoadRoomScpt") {
			std::fstream rmmsp(vstr[1],std::ios::in);
			std::vector<std::string> rmmp;
			while (std::getline(rmmsp, line)) {
				rmmp.push_back(line);
			}
			roomscripts.push_back(rmmp);
			rmmsp.close();
		}
	}
	stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, NULL, NULL);
	if (!stream) {
		SDL_Log("Couldn't create audio stream: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}
	SDL_ResumeAudioStreamDevice(stream);
	return 0;
}