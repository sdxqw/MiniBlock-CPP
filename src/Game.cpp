#include <SFML/Window.hpp>
#include "Game.h"
#include <chrono>

namespace mb {

    void Game::create() {
        this->videoMode = sf::VideoMode(800, 600);
        this->window = std::make_unique<sf::RenderWindow>(this->videoMode, "MiniBlock",
                                                          sf::Style::Titlebar | sf::Style::Close);
        this->seed = std::chrono::system_clock::now().time_since_epoch().count();
        this->chunk = std::make_unique<Chunk>(0, 0);
    }

    void Game::render() noexcept {
        this->window->clear();
        this->chunk->render(*this->window);
        this->window->display();
    }

    void Game::update(float dt) noexcept {
        this->pullEvents();

    }

    bool Game::isRunning() const noexcept {
        return this->window->isOpen();
    }

    void Game::pullEvents() noexcept {
        while (this->window->pollEvent(this->event)) {
            switch (this->event.type) {
                case sf::Event::Closed:
                    this->window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (this->event.key.code == sf::Keyboard::Escape)
                        this->window->close();
                    break;
                default:
                    break;
            }
        }
    }

    Game::~Game() noexcept {
        this->window->close();
        this->window.reset();
        this->chunk.reset();
    }
}