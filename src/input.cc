#include "input.h"

Input::Input() {
  m_key_map[UP] = sf::Keyboard::W;
  m_key_map[DOWN] = sf::Keyboard::S;
  m_key_map[LEFT] = sf::Keyboard::A;
  m_key_map[RIGHT] = sf::Keyboard::D;

  for (int k = 0; k < K_SIZE; ++k) {
    m_old_key_status[k] = m_key_status[k] = false;
  }
}

Input::~Input() {
}

void Input::update() {
  for (int k = 0; k < K_SIZE; ++k) {
    m_old_key_status[k] = m_key_status[k];
  }
  for (int k = 0; k < K_SIZE; ++k) {
    m_key_status[k] = sf::Keyboard::isKeyPressed(m_key_map[k]);
  }
}

bool Input::key_down(int key) const {
  return m_key_status[key];
}

bool Input::key_pressed(int key) const {
  return m_key_status[key] and !m_old_key_status[key];
}

bool Input::key_released(int key) const {
  return !m_key_status[key] and m_old_key_status[key];
}
