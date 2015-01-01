#include "scene.h"
#include "utils.h"
#include "game.h"
#include "config.h"

void Scene::render_grid() {
  sf::RectangleShape line;
  line.setFillColor(conf::grid_color);

  // parallel to X grid
  line.setSize(sf::Vector2f(conf::scrwidth, conf::grid_width));
  for (float i = 0; i <= conf::scrheight; i += conf::grid_size.y) {
    line.setPosition(0, i);
    game.window().draw(line);
  }

  // parallel to Y grid
  line.setSize(sf::Vector2f(conf::grid_width, conf::scrheight));
  for (float i = 0; i <= conf::scrwidth; i += conf::grid_size.x) {
    line.setPosition(i, 0);
    game.window().draw(line);
  }
}
