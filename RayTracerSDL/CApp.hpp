#ifndef CAPP_H
#define CAPP_H

#include <SDL2/SDL.h>
class CApp {
public:
  CApp();
  int OnExecute();
  bool OnInit();
  void OnLoop();
  void OnEvent(SDL_Event *e);
  void OnRender();
  void OnExit();
  SDL_Window *pWindow;
  SDL_Renderer *pRenderer;
private:
  bool isRunning;
  
};

#endif // !CAPP_H
