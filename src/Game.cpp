#include <SFML/Window.hpp>
#include <chrono>
#include "Game.h"

namespace mb {

    void Game::render() noexcept {
        window->clear();
        chunk->render(*window);
        window->display();
    }

    void Game::update([[maybe_unused]] float dt) noexcept {
        pullEvents();
    }

    bool Game::isRunning() const noexcept {
        return window->isOpen();
    }

    void Game::pullEvents() {
        sf::Event event{};
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                        window->close();
                    break;
                default:
                    break;
            }
        }
    }

    Game::~Game() noexcept {
        window->close();
    }

    Game::Game() noexcept: window(std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "Game")),
                           chunk(std::make_unique<Chunk>(sf::Vector2i(0, 0))),
                           seed(std::chrono::system_clock::now().time_since_epoch().count()),
                           assetsManager("assets/block.png", 18) {}
}