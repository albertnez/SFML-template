#include "game.h"
#include "scene_base.h"

int main() {
  Game game;
  if (game.init()) {
    game.set_scene(new SceneBase(game));
    game.run();
  }
  return 0;
}
