#pragma once

#include <memory>
#include "SFML/Graphics.hpp"
#include "chunk/Chunk.h"

namespace mb {
    class Game {
    private:
        std::unique_ptr<sf::RenderWindow> window;
        std::unique_ptr<Chunk> chunk;
        int64_t seed{};
    public:
        Game() noexcept;

        ~Game() noexcept;

        [[nodiscard]] bool isRunning() const noexcept;

        void pullEvents();

        void render() noexcept;

        void update([[maybe_unused]] float dt) noexcept;
    };
}