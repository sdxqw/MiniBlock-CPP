#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "block/Block.h"

namespace mb {
    class Chunk {
    private:
        sf::Vector2i position;
        std::vector<std::vector<Block>> blocks;
    public:
        explicit Chunk(sf::Vector2i position);

        [[nodiscard]] int getX() const noexcept;

        [[nodiscard]] int getY() const noexcept;

        void render(sf::RenderWindow &window) const;

        static const int SIZE = 16;
    };
}
