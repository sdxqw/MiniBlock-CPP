#pragma once

#include <memory>
#include "SFML/Graphics.hpp"
#include "chunk/Chunk.h"

namespace mb {
    class Game {
    private:
        std::unique_ptr<sf::RenderWindow> window;
        sf::Event event{};
        sf::VideoMode videoMode;
        std::unique_ptr<Chunk> chunk;
        long long seed{};
    public:
        Game() noexcept = default;

        ~Game() noexcept;

        [[nodiscard]] bool isRunning() const noexcept;

        void pullEvents() noexcept;

        void create();

        void render() noexcept;

        void update(float dt) noexcept;
    };
}