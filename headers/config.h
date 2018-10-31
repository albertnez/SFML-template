#pragma once

#include "utils.h"

namespace conf {

  extern std::string window_title;
  extern sf::ContextSettings context_settings;

  extern int scrwidth;
  extern int scrheight;

  extern bool debug;

  extern sf::Color clear_color;
  extern sf::Color grid_color;
  extern sf::Vector2f grid_size;
  extern float grid_width;

  // Player config
  extern sf::Color player_color;
  extern sf::Vector2f player_init_pos;
  extern sf::Vector2f player_size;
  extern float player_speed;
}
