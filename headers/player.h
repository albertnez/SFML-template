#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"
#include "utils.h"

class Player : public GameObject {
public:
  Player(Game &game);
  ~Player();
  void update(float delta_time);
  void render();
private:
  sf::Vector2f pos;
  sf::Vector2f size;
  float speed;
};

#endif // PLAYER_H
