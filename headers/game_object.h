#pragma once

class Game;

class GameObject {
public:
  GameObject(Game &game) : game(game) {};
  virtual ~GameObject() {};
  virtual void update(float delta_time) = 0;
  virtual void render() = 0;

protected:
  Game& game;
};
