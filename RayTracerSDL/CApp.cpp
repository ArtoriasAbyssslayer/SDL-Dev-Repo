#include "CApp.hpp"



// The constructor (default)
CApp::CApp(){
  isRunning = true;
  pWindow = NULL;
  pRenderer = NULL;
}

bool CApp::OnInit()
{
  if(SDL_Init(SDL_INIT_EVERYTHING) <0){
    return false;
  }

  pWindow = SDL_CreateWindow("qbRayTracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,1280,720,SDL_WINDOW_SHOWN);
  if(pWindow != NULL){
    pRenderer = SDL_CreateRenderer(pWindow, -1,0);
  }else {
    return false;
  }
  return true;
}

int CApp::OnExecute(){
  SDL_Event event;
  if(OnInit() == false)
      return -1;

  while(isRunning){
    while (SDL_PollEvent(&event)!=0) 
    {
      OnEvent(&event);
    }
    OnLoop();
    OnRender();
  }
  return 1;
}



void CApp::OnEvent(SDL_Event *event){
  if(event->type == SDL_QUIT)
  {
    isRunning = false;
  }
}
void CApp::OnLoop()

{

}

void CApp::OnRender(){
  //Set the background to white color
  SDL_SetRenderDrawColor(pRenderer,255,255,255,255);
  SDL_RenderClear(pRenderer);
  SDL_RenderPresent(pRenderer);

}

void CApp::OnExit(){

  //Tidy up SDL2 stuff
  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(pWindow);
  pWindow=NULL;
  SDL_Quit();
}

