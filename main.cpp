#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_thread.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "ROOMS/rooms.h"
#include "loader/loader.h"
#include "drawsth/drawsth.h"
#include "music.h"
#include <codecvt>
#include <locale>
#include <boost/algorithm/string.hpp>
#pragma execution_character_set("utf-8")
#define gamename "galgame booger aids"
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_AudioStream* stream = NULL;
int WindowH=480, WindowW=640;
double delay_now = 0;
bool showbtn = false;
bool btnentered = false;
bool gogogogo = false;
float btnx = -640;
bool delreded = false;
bool tiaoguo = false;
float MouseX = 0, MouseY = 0;
double before = 0;
bool keyihuanle = false;
int tick = 0;
int FPS = 0;
bool ShowDebugToolTips = false;
int ROOM = 0;
bool ldfail = false;
int errtyp = 0;
bool dawanle = false;
float menustartbuttonxpos = 0;
float mssbtxps = 0;
float msextxps = 0;
double fpss = 0;
double tbf = 0;
int mncsd = 0;
int drtxmd = 0;
float sddst1y = 138;
float testvar = 114514;
bool bigmode = true;
float sddst1w=112;
int CGnumber = 0;
int btn_c = -1;
std::vector<Sounds>wavfiles;
int musplaying = 0;
double wait = 1;
float textboxy =480;
bool showtextbox = false;
int dazishushu = 1;
SDL_Thread* ldthrd = NULL;
std::vector<SDL_Surface*> Imgs = {};
std::vector<TTF_Font*> Fonts = {};
std::string Task = "None";
std::vector<std::vector<std::string>> roomscripts;
int roomsc_pointer = 0;
std::string cfgph = "";
/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
	SDL_SetAppMetadata(gamename, "1.0", "127.0.0.1");
	std::fstream sczs("./Data/sceensz.cfg", std::ios::in);
	std::string sczs2;
	sczs >> sczs2;
	sczs.close();
	int scccccc= atoi(sczs2.c_str());
	SDL_Log(std::to_string(scccccc).c_str());
	if (scccccc == 0) {
		bigmode = false;
	}
	else {
		bigmode = true;
	}
	if (bigmode) {
		WindowH = 960;
		WindowW = 1280;
	}
	if (!SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer(gamename, WindowW, WindowH, 0, &window, &renderer)) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!TTF_Init())
	{
		std::cout << "SDL_ttf could not initialize! SDL_ttf Error " << std::endl;
		return SDL_APP_FAILURE;
	}
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	ldthrd = SDL_CreateThread(LoadGame, "LoadGame", (void*)NULL);
	return SDL_APP_CONTINUE;  /* carry on with the program! */
}
void SaveGame() {
	SDL_Log("SaveConfigFile");
	std::fstream cfg(cfgph, std::ios::out);
	cfg << drtxmd << " ";
	cfg << 114514 << " ";
	cfg.close();
	std::fstream cffffffff("./Data/sceensz.cfg", std::ios::out);
	if (bigmode)
		cffffffff << "1";
	else
	{
		cffffffff << "0";
	}
	cffffffff.close();
}
void changebgm(int a=-1)
{
	if (ShowDebugToolTips)
	{

		if (musplaying + 1 < wavfiles.size()) {
			musplaying += 1;
		}
		else {
			musplaying = 0;
		}
		SDL_ClearAudioStream(stream);
	}
	if (a != -1) {
		if (a < wavfiles.size()) {
			musplaying =a;
		}
		else {
		}
		SDL_ClearAudioStream(stream);
	}
}
/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
	if (event->type == SDL_EVENT_QUIT) {
		return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
	}
	else if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
		if (event->button.button == SDL_BUTTON_LEFT) {
			if (ROOM == 1) {
				if (mncsd == 3) {
					return SDL_APP_SUCCESS;
				}
				else if (mncsd == 2) {
					SDL_Log("ROOM = 2");
					mncsd = 0;
					ROOM = 2;
				}
				else if (mncsd == 1) {
					ROOM = 3;
					SDL_Log("ROOM = 3");
				}
			}
			else if (ROOM == 2) {
				if (mncsd == 4) {
					drtxmd = 0;
				}
				if (mncsd == 6) {
					drtxmd = 2;
				}
				if (mncsd == 5) {
					drtxmd = 1;
				}
				if (mncsd == 8) {
					mncsd = 0;
					SaveGame();
					SDL_Log("ROOM = 1");
					ROOM = 1;
				}
				if (mncsd == 9) {
					if (bigmode) {
						bigmode = false;
						WindowH = 480;
						WindowW = 640;
					}
					else {
						bigmode = true;
						WindowH = 960;
						WindowW = 1280;
					}
					SDL_SetWindowSize(window, WindowW, WindowH);
					SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
				}
			}else
			if (dawanle) {
				keyihuanle = true;
			}
			else {
				if(showtextbox)
				tiaoguo = true;
			}
			if (btn_c != -1) {
				gogogogo = true;
			}
		}
	}
	else if (event->type == SDL_EVENT_KEY_DOWN) {
		if (event->key.key == SDLK_INSERT) {
			if (ShowDebugToolTips)
			{
				ShowDebugToolTips = false;
			}
			else
			{
				ShowDebugToolTips = true;
			}
		}
		else if (event->key.key == SDLK_PAGEDOWN) {
			changebgm();
		}
	}
	return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void* appstate)
{
	if(ROOM!=0){
	if (SDL_GetAudioStreamQueued(stream) < (int)wavfiles[musplaying].wav_data_len) {
		SDL_PutAudioStreamData(stream, wavfiles[musplaying].wav_data, wavfiles[musplaying].wav_data_len);
	}
}
	SDL_GetMouseState(&MouseX, &MouseY);
	tick++;
	const double now = ((double)SDL_GetTicks()) / 1000.0;  /* convert from milliseconds to seconds. */
	double delt = now - tbf;
	fpss = 1.f / (delt);
	tbf = now;
	/* choose the color for the frame we will draw. The sine wave trick makes it fade between colors smoothly. */
	if (now - before >= 1) {
		FPS = tick;
		tick = 0;
		before = now;
	}

	switch (ROOM)
	{
	case 0:
	{
		room0();
		break;
	}
	case 1:
	{
		SDL_SetRenderScale(renderer, 1.0f, 1.0f);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		SDL_Texture* tmp_texture = SDL_CreateTextureFromSurface(renderer, Imgs[0]);
		SDL_FRect rect = { 0,0 ,640,480 };
		SDL_RenderTexture(renderer, tmp_texture, NULL, &rect);
		SDL_DestroyTexture(tmp_texture);
		room1_updt();
		RenderText(gamename, Fonts[1], 0, 0, 0, 0, 0);
		RenderText("设置", Fonts[3], 0, 0, 0, mssbtxps, 188);
		RenderText("开始游戏", Fonts[3], 0, 0, 0, menustartbuttonxpos, 150);
		RenderText("退出", Fonts[3], 0, 0, 0, msextxps, 226);
		RenderText("什么击败", Fonts[0], 0, 0, 0, 0, 50);
		break;
	}
	case 2:
	{
		room2_updt();
		SDL_SetRenderScale(renderer, 1.0f, 1.0f);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		SDL_Texture* tmp_texture = SDL_CreateTextureFromSurface(renderer, Imgs[0]);
		SDL_FRect ect3 = { 0,0, 640,480 };
		SDL_RenderTexture(renderer, tmp_texture, NULL, &ect3);
		SDL_DestroyTexture(tmp_texture);
		const SDL_FRect ect = { 0,sddst1y,sddst1w,38 };
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);
		SDL_RenderFillRect(renderer, &ect);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 25);
		const SDL_FRect ect2 = { 0,138 + drtxmd * 38,112,38 };
		SDL_RenderFillRect(renderer, &ect2);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		RenderText(gamename, Fonts[1], 0, 0, 0, 0, 0);
		RenderText("设置页面", Fonts[0], 0, 0, 0, 0, 50);
		RenderText("文本质量", Fonts[3], 0, 0, 0, 0, 100);
		RenderText("高", Fonts[3], 0, 0, 0, 38, 138);
		RenderText("中", Fonts[3], 0, 0, 0, 38, 176);
		RenderText("低", Fonts[3], 0, 0, 0, 38, 214);
		RenderText("窗口大小", Fonts[3], 0, 0, 0, 0, 214 + 38);
		if (bigmode)
			RenderText("大(点击切换为小)", Fonts[3], 0, 0, 0, 0, 214 + 38 * 2);
		else
			RenderText("小(点击切换为大)", Fonts[3], 0, 0, 0, 0, 214 + 38 * 2);
		RenderText("主菜单", Fonts[3], 0, 0, 0, msextxps, 400);
		break;
	}
	default:
	{
		SDL_SetRenderScale(renderer, 1.0f, 1.0f);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		SDL_Texture* cg = SDL_CreateTextureFromSurface(renderer, Imgs[CGnumber]);
		SDL_FRect ect3 = { 0,0, 640,480 };
		SDL_RenderTexture(renderer, cg, NULL, &ect3);
		SDL_DestroyTexture(cg);
		std::vector<std::string> vstr;
		if (roomsc_pointer < roomscripts[ROOM - 3].size())
		{
			std::string sds = roomscripts[ROOM - 3][roomsc_pointer];
			boost::split(vstr, sds, boost::is_any_of(" "), boost::token_compress_on);
			if (vstr[0] == "SetCG") {
				CGnumber = atoi(vstr[1].c_str());
				SDL_Log(("CGnumber=" + std::to_string(CGnumber)).c_str());
				roomsc_pointer++;
			}
			else if (vstr[0] == "Character.say") {
				showtextbox = true;
			}
			else if (vstr[0] == "HideTextBox") {
				showtextbox = false;
				roomsc_pointer++;
			}
			else if (vstr[0] == "Delay") {
				if (delreded) {
					if (now - delay_now > atoi(vstr[1].c_str())) {
						roomsc_pointer++;
						delreded = false;
					}
				}
				else
				{
					delreded = true;
					delay_now = now;
				}
			}
			else if (vstr[0] == "Button") {
				int y = atoi(vstr[1].c_str()) * 40;
				for (size_t i = 0; i < atoi(vstr[1].c_str()); i++)
				{
					if (i == btn_c) {
						SDL_Texture* btn = SDL_CreateTextureFromSurface(renderer, Imgs[7]);
						SDL_FRect ect3 = { btnx,(329 - y) / 2 + i * 40, 640,480 };
						SDL_RenderTexture(renderer, btn, NULL, &ect3);
						SDL_DestroyTexture(btn);
						std::string tmmmdm = vstr[(i + 1) * 2];
						boost::algorithm::replace_all(tmmmdm, "[space]", " ");
						RenderText(tmmmdm.c_str(), Fonts[4], 0, 0, 0, 90 + btnx, (329 - y) / 2 + i * 40 + 1);
					}
					else {
						SDL_Texture* btn = SDL_CreateTextureFromSurface(renderer, Imgs[6]);
						SDL_FRect ect3 = { btnx,(329 - y) / 2 + i * 40, 640,480 };
						SDL_RenderTexture(renderer, btn, NULL, &ect3);
						SDL_DestroyTexture(btn);
						std::string tmmmdm = vstr[(i + 1) * 2];
						boost::algorithm::replace_all(tmmmdm, "[space]", " ");
						RenderText(tmmmdm.c_str(), Fonts[4], 0, 0, 0, 90 + btnx, (329 - y) / 2 + i * 40 + 1);
					}
				}
				if (btnentered) {
					btnx += (0 - btnx) / fpss * 10;
					for (size_t j = 0; j < atoi(vstr[1].c_str()); j++)
					{
						if (bigmode) {
							if (MouseX > 83*2 && MouseX < 557*2) {
								if (MouseY > ((329 - y) / 2 + j * 40)*2 && MouseY < ((329 - y) / 2 + j * 40 + 30)*2) {
									btn_c = j;
								}
								if (MouseY < ((329 - y) / 2)*2) {
									btn_c = -1;
								}
								if (MouseY > ((329 - y) / 2 + (atoi(vstr[1].c_str())) * 40)*2) {
									btn_c = -1;
								}
							}
							else {
								btn_c = -1;
							}
						}
						else {
							if (MouseX > 83 && MouseX < 557) {
								if (MouseY > (329 - y) / 2 + j * 40 && MouseY < (329 - y) / 2 + j * 40 + 30) {
									btn_c = j;
								}
								if (MouseY < (329 - y) / 2) {
									btn_c = -1;
								}
								if (MouseY > (329 - y) / 2 + (atoi(vstr[1].c_str())) * 40) {
									btn_c = -1;
								}
							}
							else {
								btn_c = -1;
							}
						}
					}
					if (gogogogo) {
						ROOM = atoi(vstr[(btn_c+1) * 2+1].c_str());
						gogogogo = false;
						roomsc_pointer = 0;
						showbtn = false;
						showtextbox = false;
						btnx = -640;
						textboxy = 480;
						dazishushu = 1;
						wait = 1;
						keyihuanle = false;
						dawanle = false;
						tiaoguo = false;
						btn_c = -1;
					}
				}
				else {
					btnx += (0 - btnx)/fpss * 10;
					if (btnx > -5) {
						btnentered = true;
					}
				}
				}
			else if (vstr[0] == "SetRoom") {
					ROOM = atoi(vstr[1].c_str());
					gogogogo = false;
					roomsc_pointer = 0;
					showbtn = false;
					showtextbox = false;
					btnx = -640;
					textboxy = 480;
					dazishushu = 1;
					wait = 1;
					keyihuanle = false;
					dawanle = false;
					tiaoguo = false;
					btn_c = -1;
			}
			else if (vstr[0] == "SetBGM") {
				changebgm(atoi(vstr[1].c_str()));
				roomsc_pointer++;
				}
		}
		if (showtextbox)
		{
			textboxy += (0 - textboxy) / fpss * 10;
		}
		else {
			textboxy += (480 - textboxy) / fpss * 10;
		}
		ect3 = { 0,textboxy, 640,480 };
		SDL_Texture* textbox = SDL_CreateTextureFromSurface(renderer, Imgs[2]);
		SDL_RenderTexture(renderer, textbox, NULL, &ect3);
		SDL_DestroyTexture(textbox);
		if (vstr[0] == "Character.say") {
			std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
			std::string tmmmm = vstr[2];
			boost::algorithm::replace_all(tmmmm, "[space]", " ");
			std::wstring text = converter.from_bytes(tmmmm);
			if (dazishushu < text.size())
			{
				wait += (-1 - wait) / fpss * 10;
				if (wait <= 0) {
					dazishushu++;
					wait = 1;
				}
			}
			else {
				dawanle = true;
			}
			
			RenderText(vstr[1].c_str(), Fonts[4], 0, 0, 0, 60, textboxy + 335);
			RenderText_Wrapped(converter.to_bytes(text.substr(0, dazishushu)).c_str(), Fonts[4], 0, 0, 0, 60, textboxy + 352, 520);
			if (keyihuanle) {
				dazishushu = 1;
				wait = 1;
				keyihuanle = false;
				dawanle = false;
				roomsc_pointer++;
			}
			if (tiaoguo) {
				dazishushu = text.size();
				tiaoguo = false;
			}
		}
		break;
	}
	}
	if (ShowDebugToolTips) {
		SDL_SetRenderScale(renderer, 1.0f, 1.0f);
		const SDL_FRect ect = { 0,0,640,480 };
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 126);
		SDL_RenderFillRect(renderer, &ect);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDebugText(renderer, 0, 0, ("Time=" + std::to_string(now)).c_str());
		SDL_RenderDebugText(renderer, 0, 10, ("FPS=" + std::to_string(FPS) + "(" + std::to_string(tick) + ")" + std::to_string(fpss)).c_str());
		SDL_RenderDebugText(renderer, 0, 20, ("MousePos:" + std::to_string(MouseX) + "," + std::to_string(MouseY)).c_str());
		SDL_RenderDebugText(renderer, 0, 30, ("int mncsd=" + std::to_string(mncsd)).c_str());
		SDL_RenderDebugText(renderer, 0, 40, ("int ROOM=" + std::to_string(ROOM)).c_str());
		SDL_RenderDebugText(renderer, 0, 50, ("int testvar=" + std::to_string(testvar)).c_str());
		SDL_RenderDebugText(renderer, 0, 60, ("int musplaying=" + std::to_string(musplaying)+"(Press PgDown to Change)").c_str());
		SDL_RenderDebugText(renderer, 0, 70, ("int btn_c=" + std::to_string(btn_c)).c_str());
#define drbg 80
		SDL_RenderDebugText(renderer, 0, drbg, ("Fonts:" + std::to_string(Fonts.size())).c_str());
		for (int i = 0; i < Fonts.size(); i++)
		{
			if (Fonts[i]) {
				std::string fntsname(TTF_GetFontStyleName(Fonts[i])), fntfname(TTF_GetFontFamilyName(Fonts[i]));
				SDL_RenderDebugText(renderer, 20, drbg + (i + 1) * 10, (fntfname + " " + fntsname + " " + std::to_string(TTF_GetFontSize(Fonts[i]))).c_str());
			}
			else {
				SDL_RenderDebugText(renderer, 20, drbg + (i + 1) * 10, "NULL");
			}
		}
	}
	if (bigmode)
	{
	SDL_Rect rectsb = { 0,0,640,480 };
	SDL_FRect rectsb2 = { 0,0,1280,960 };
	if (ROOM == 0) { rectsb = { 0,0,1280,960 }; rectsb2 = { 0,0,640,480 };}
	SDL_Surface* tmpsbbb = SDL_RenderReadPixels(renderer, &rectsb);
	SDL_Texture* tmp_texture2 = SDL_CreateTextureFromSurface(renderer, tmpsbbb);
	SDL_SetTextureScaleMode(tmp_texture2, SDL_SCALEMODE_NEAREST);
	SDL_RenderTexture(renderer, tmp_texture2, NULL, &rectsb2);
	SDL_DestroyTexture(tmp_texture2);
	SDL_DestroySurface(tmpsbbb);
}
	/* put the newly-cleared rendering on the screen. */
	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
	SDL_Log("QUIT");
	SDL_free(appstate);
	/* SDL will clean up the window/renderer for us. */
}