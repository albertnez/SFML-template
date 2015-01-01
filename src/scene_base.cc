#include "scene_base.h"
#include "utils.h"
#include "player.h"
#include "config.h"

SceneBase::SceneBase(Game &game) : Scene(game) {
}

SceneBase::~SceneBase() {
}

bool SceneBase::init() {
  std::cerr << "Init SceneBase" << std::endl;
  m_game_objects.push_back(new Player(game));
  return true;
}

void SceneBase::update(float delta_time) {
  for (GameObject* game_object : m_game_objects) {
    game_object->update(delta_time);
  }
}

void SceneBase::render() {
  for (GameObject* game_object : m_game_objects) {
    game_object->render();
  }
  if (conf::debug) render_grid();
}

void SceneBase::on_close() {
  std::cerr << "close SceneBase" << std::endl;
}

