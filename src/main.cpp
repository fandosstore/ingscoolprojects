#include "SDL2/SDL.h"
#include <iostream>
#include "unistd.h"
#include "GL/glew.h"
using std::cout;
using std::endl;



int main(){
	//INIT_GRAPHIC//////////////////////////
	////////////////////////////////////////
	int res0 = SDL_Init(SDL_INIT_EVERYTHING);
	if(0 != res0) return 1;
	SDL_Window *win = SDL_CreateWindow("name", 100, 100, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);	
	SDL_GLContext glcontext = SDL_GL_CreateContext(win);
	//glOrtho(-1.0, 1.0, -1.0, 1.0, 0.0, 0.0);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	//MAIN_CYCLE/////////////////////////////
	/////////////////////////////////////////
	bool running = true;
	while(running){
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_Event event;
		while (SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					running = false;
				break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym){
						case SDLK_ESCAPE:
							running = false;
						break;
					}
				break;
			}
		}
		
		
		glFlush();
		SDL_GL_SwapWindow(win);
	}
	SDL_DestroyWindow(win);
	SDL_Quit();
}
