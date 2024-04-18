#include <Player.h>
#include <iostream>
Player::Player(SDL_Renderer* renderer, const char* imagePath, int x, int y, int speed, int health, dir direction, int attackDamage){
    direction = NULLDIR;
    SDL_Surface* surface = SDL_LoadBMP(imagePath);
    if (!surface) {
        // Handle error
        // For simplicity, we're just printing an error message
        printf("Failed to load image: %s\n", SDL_GetError());
        texture = nullptr;
    }
    else {
        // Convert surface to texture
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!texture) {
            // Handle error
            printf("Failed to create texture: %s\n", SDL_GetError());
        }
        SDL_FreeSurface(surface);
    }
    hitbox.x = x;
    hitbox.y = y;
    hitbox.radius = 10;
    hitbox.height = 20;
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->health = health;
    this->direction = direction;
    this->attackDamage = attackDamage;
}
Player::~Player() {
    // Free player texture
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

bool Player::checkCollision(CapsuleHitbox a, CapsuleHitbox b) {
    // Calculate squared distance between centers
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    int distance = (dx * dx) + (dy * dy);

    // Calculate squared sum of radii
    int radii = a.radius + b.radius;
    radii *= radii;

    // If the distance between the centers is less than the sum of the radii, a collision has occurred
    if (distance < radii) {
        return true;
    }
    return false;
}

void Player::draw(SDL_Renderer* renderer) {
    // Render player texture at current position
    SDL_Rect destRect = { x, y, 10, 20 }; // Assuming player size is 10x20
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}

void Player::move(int x, int y, int speed) {
	x += speed;
	y += speed;
}
void Player::update(Player p, dir direction, int speed) {
    // Update player position based on direction
    switch (direction) {
    case UP:
        move(p.getX(), p.getY(), -speed);
        break;
    case DOWN:
        move(p.getX(), p.getY(), speed);
        break;
    case LEFT:
        move(p.getX(), p.getY(), -speed);
        break;
    case RIGHT:
        move(p.getX(), p.getY(), speed);
        break;
    default:
        break;
    }
}
