#include "Game.h"

int main() {
    mb::Game game;
    game.create();

    while (game.isRunning()) {
        game.update(0.0f);
        game.render();
    }

    return 0;
}
