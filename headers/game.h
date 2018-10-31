#pragma once

#include "input.h"
#include "utils.h"

class Scene;

class Game {
public:
  Game();
  ~Game();

  bool init();
  void run();
  void set_scene(Scene *scene);
  void update(float delta_time);
  void render();
  void on_close();
  void close();

  sf::RenderWindow &window();
  const Input &input() const;

protected:
  sf::RenderWindow m_window;
  Input m_input;
  Scene* m_current_scene;
  Scene* m_next_scene;
  bool m_is_running;
};
