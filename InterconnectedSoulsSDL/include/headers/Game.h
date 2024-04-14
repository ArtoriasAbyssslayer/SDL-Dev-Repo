#ifndef GAME_H
#define GAME_H
#pragma once
#include <SDL2/SDL.h>
#include <iostream>

class Game {
public:
    Game();
    ~Game();
    void init(const char* game_title, int x_pos, int y_pos, int canvas_width, int canvas_height, int fullscreen_flag);
    void handle_events();
    void update();
    void render();
    void clean();
    bool running() const { return !game_over; }  // Invert the logic for clarity
private:
    SDL_Window* s_Window;
    SDL_Renderer* s_Renderer;
    int counter;
    bool game_over;
};
#endif