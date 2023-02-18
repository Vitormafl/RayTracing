#ifndef CAPP.H
#define CAPP.H

#include <SDL2/SDL.h>

class CApp
{
  public:
    CApp();
    
    int onExecute();
    bool onInit();
    void onEvent(SDL_Event *event);
    void onLoop();
    void onRender();
    void onExit();

  private:

    bool isRunning;
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;

};

#endif