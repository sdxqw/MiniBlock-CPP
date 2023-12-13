#include "Game.h"
#include <SFML/System/Clock.hpp>

int main() {
    sf::Clock clock;
    mb::Game game;

    while (game.isRunning()) {
        sf::Time deltaTime = clock.restart();
        game.update(deltaTime.asSeconds());
        game.render();
    }

    return 0;
}
