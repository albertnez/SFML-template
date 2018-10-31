#include "game.h"
#include "config.h"
#include "scene.h"

Game::Game() {
  m_current_scene = m_next_scene = NULL;
  m_window.create(sf::VideoMode(conf::scrwidth, conf::scrheight, 32),
                  conf::window_title,
                  sf::Style::Default,
                  conf::context_settings);
}

Game::~Game() {
}

bool Game::init() {
  m_is_running = true;
  return true;
}

void Game::run() {
  sf::Clock clock;
  while (m_is_running) {
    float delta_time = clock.restart().asSeconds();
    update(delta_time);
    render();
  }
}

void Game::set_scene(Scene *scene) {
  if (m_next_scene != NULL) {
    delete m_next_scene;
  }
  m_next_scene = scene;
}

void Game::update(float delta_time) {
  if (m_next_scene != NULL) {
    if (m_current_scene != NULL) {
      delete m_current_scene;
    }
    m_current_scene = m_next_scene;
    m_next_scene = NULL;
    if (!m_current_scene->init()) {
      delete m_current_scene;
      m_current_scene = NULL;
      on_close();
    }
  }

  // SFML events
  sf::Event event;
  while(m_window.pollEvent(event)) {
    switch(event.type) {
      case sf::Event::Closed:
        on_close();
        break;
      case sf::Event::Resized:
        conf::scrwidth = event.size.width;
        conf::scrheight = event.size.height;
        m_window.setView(sf::View(sf::FloatRect(0, 0, conf::scrwidth, conf::scrheight)));
      default:
        break;
    }
  }

  // Input
  m_input.update();

  // Scene update
  if (m_current_scene != NULL) {
    m_current_scene->update(delta_time);
  }
}

void Game::render() {
  m_window.clear(conf::clear_color);
  if (m_current_scene != NULL)
    m_current_scene->render();
  m_window.display();
}

// function when you want to close the game
void Game::on_close() {
  if (m_current_scene != NULL) {
    m_current_scene->on_close();
  }
  std::cout << "* EXITING GAME" << std::endl;
  close();
}

// End game
void Game::close() {
  if (m_current_scene != NULL) {
    delete m_current_scene;
    m_current_scene = NULL;
  }
  m_is_running = false;
  m_window.close();
}

sf::RenderWindow &Game::window() {
  return m_window;
}

const Input &Game::input() const {
  return m_input;
}
