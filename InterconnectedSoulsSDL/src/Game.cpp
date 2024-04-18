#include <Game.h>
#include <cstdlib>
#include <cmath>
SDL_Texture* playerSprite;
Game::Game() : s_Window(nullptr), s_Renderer(nullptr), game_over(false) {
	// Initialize SDL and other resources here
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		// Handle initialization error
		// You might want to throw an exception or set game_over to true
		game_over = true;
		return;
	}

	// Initialize the window and renderer
	s_Window = SDL_CreateWindow("Interconnected Souls", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (!s_Window) {
		// Handle window creation error
		game_over = true;
		return;
	}

	s_Renderer = SDL_CreateRenderer(s_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!s_Renderer) {
		// Handle renderer creation error
		game_over = true;
		return;
	}
}

Game::~Game() {
	// Clean up SDL and other resources here
	if (s_Renderer) {
		SDL_DestroyRenderer(s_Renderer);
	}

	if (s_Window) {
		SDL_DestroyWindow(s_Window);
	}

	SDL_Quit();
}

void Game::handle_events()
{
	SDL_Event e; 
	SDL_PollEvent(&e);
	switch (e.type)
	{
	case SDL_QUIT:
		game_over = true;
		break;
	default:
		printf("Game running, Event not handled\n");
		break;

	}
}
void Game::init(const char* game_title, int x_pos, int y_pos, int canvas_width, int canvas_height, int fullscreen_flag)
{
	//attempt to initialilze sdl
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL_initialized" << std::endl;

		// init window
		s_Window = SDL_CreateWindow(game_title, x_pos, y_pos, canvas_width, canvas_height, fullscreen_flag);

		if (s_Window) // window entity created
		{
			std::cout << "Game Window Created\n";
			s_Renderer = SDL_CreateRenderer(s_Window, -1, 0);

			if(!s_Renderer)
			{
#				//TODO: add error handling
				std::cout << "Renderer creation failed" << std::endl;
			}
			else
			{
				// Draw a white background
				std::cout << "Renderer created" << std::endl;
				SDL_SetRenderDrawColor(s_Renderer, 25, 25, 25, 4);
			}
		}
	}
	SDL_Surface* tempSurface = IMG_Load("assets/mage.png");
	playerSprite = SDL_CreateTextureFromSurface(s_Renderer,tempSurface);

}



void Game::update() {
	counter++;
	std::cout << counter << "\n";
}

void Game::render() {
	// Implement rendering logic
	SDL_RenderClear(s_Renderer);
	// Add rendering code here
	SDL_RenderCopy(s_Renderer, playerSprite, NULL, NULL);
	SDL_RenderPresent(s_Renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(s_Window);
	SDL_DestroyRenderer(s_Renderer);
	SDL_Quit();
}
