#ifndef CAPP_H
#define CAPP_H

#include <SDL2/SDL.h>
#include "./qbImage.hpp"

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
  //An instance of qbImage class to store the qbImage
  qbImage m_image;
  
};

#endif // !CAPP_H
