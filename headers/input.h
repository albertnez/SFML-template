#ifndef INPUT_H
#define INPUT_H

#include "utils.h"

class Input {
public:
  enum Key {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    K_SIZE
  };
  Input();
  ~Input();
  void update();
  bool key_down(int key) const;
  bool key_pressed(int key) const;
  bool key_released(int key) const;

private:
  bool m_key_status[K_SIZE];
  bool m_old_key_status[K_SIZE];
  sf::Keyboard::Key m_key_map[K_SIZE];
};

#endif // INPUT_H
