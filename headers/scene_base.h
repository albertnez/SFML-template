#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include "scene.h"
#include "game_object.h"
#include <list>

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

#endif // SCENE_BASE_H

