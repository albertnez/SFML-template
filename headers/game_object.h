#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
// Forward declaration
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

#endif // GAME_OBJECT_H
