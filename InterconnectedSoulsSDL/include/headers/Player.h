#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include <SDL2/SDL.h>
/*
	Player class represents the player character in the game.
*/


// CapsuleHitbox is a struct that represents a capsule-shaped hitbox.

struct CapsuleHitbox {
	int x, y; // eclipse center spot
	int radius; // arbitrary hitbox size 
	int height; // arbitrary hitbox size
};


// Enum for player direction
enum dir { UP, DOWN, LEFT, RIGHT, NULLDIR };
class Player {
public:
	Player(SDL_Renderer* renderer, const char* imagePath, int x, int y, int speed, int health, dir direction, int attackDamage);
	~Player();
	// Getters
	int getX() {return x;}
	int getY() {return y;}
	int getSpeed() {return speed;}
	int getHealth() {return health;}
	dir getDirection() {return direction;}
	int getAttackDamage() {return attackDamage;}
	// Setters
	inline void setX(int x) {this->x = x;}
	inline void setY(int y) {this->y = y;}
	inline void setSpeed(int speed) {this->speed = speed;}
	inline void setHealth(int health) {this->health = health;}
	inline void setDirection(dir direction) {this->direction = direction;}
	inline void setAttackDamage(int attackDamage) {this->attackDamage = attackDamage;}
	// Functions
	static bool checkCollision(CapsuleHitbox a, CapsuleHitbox b);
	void move(int x, int y, int speed);
	void draw(SDL_Renderer* renderer);
	void update(Player p, dir direction, int speed);
private:
	SDL_Texture* texture;
	int x, y;
	CapsuleHitbox hitbox;
	int speed;
	int health;
	dir direction;
	int attackDamage;
};

#endif
