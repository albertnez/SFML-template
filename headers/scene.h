#ifndef SCENE_H
#define SCENE_H

class Game;

class Scene {
public:
  Scene(Game &game) : game(game) {};
  virtual ~Scene() {};
  virtual bool init() = 0;
  virtual void update(float delta_time) = 0;
  virtual void render() = 0;
  virtual void on_close() = 0;

protected:
  void render_grid();
  Game &game;
};

#endif // SCENE_H

