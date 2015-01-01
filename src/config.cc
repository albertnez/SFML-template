#include "config.h"

namespace conf {

  std::string window_title("Template");
  sf::ContextSettings context_settings(sf::ContextSettings(32, 32, 0, 2, 0));

  int scrwidth = 800;
  int scrheight = 480;

  bool debug = true;

  sf::Color clear_color = sf::Color::White;
  sf::Color grid_color = sf::Color::Green;
  sf::Vector2f grid_size(32.0f, 32.0f); // X, Y size of grid
  float grid_width(1.0f);
  

  // Player config
  sf::Color player_color = sf::Color::Red;
  sf::Vector2f player_init_pos(0.0f, 0.0f);
  sf::Vector2f player_size(32.0f, 32.0f);
  float player_speed(320.0f);

}

