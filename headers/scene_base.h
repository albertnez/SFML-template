#pragma once

#include "scene.h"

#include <list>

class Game;
class GameObject;

class SceneBase : public Scene {
public:
  SceneBase(Game &game);
  ~SceneBase();
  bool init();
  void update(float delta_time);
  void render();
  void on_close();

private:
  std::list<GameObject*> m_game_objects;
};
