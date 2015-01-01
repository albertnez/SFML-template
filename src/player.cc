#include "player.h"
#include "game.h"
#include "config.h"

Player::Player(Game &game) :
  GameObject(game),
  pos(conf::player_init_pos),
  size(conf::player_size),
  speed(conf::player_speed) {
}

Player::~Player() {
}

void Player::update(float delta_time) {
  if (game.input().key_down(Input::LEFT)) {
    pos.x -= speed * delta_time;
  }
  else if (game.input().key_down(Input::RIGHT)) {
    pos.x += speed * delta_time;
  }
  if (game.input().key_down(Input::UP)) {
    pos.y -= speed * delta_time;
  }
  else if (game.input().key_down(Input::DOWN)) {
    pos.y += speed * delta_time;
  }
}

void Player::render() {
  sf::RectangleShape rectangle(size);
  rectangle.setPosition(pos);
  rectangle.setFillColor(conf::player_color);
  game.window().draw(rectangle);
}
