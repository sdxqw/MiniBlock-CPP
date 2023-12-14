#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "block/Block.h"

namespace mb {
    class Chunk {
    private:
        sf::Vector2i position;
        std::vector<Block> blocks;
    public:
        explicit Chunk(sf::Vector2i position);

        [[nodiscard]] sf::Vector2i getPosition() const noexcept;

        void render(sf::RenderWindow &window) const;

        Block& at(int x, int y);
        [[nodiscard]] const Block& at(int x, int y) const;

        static const int SIZE = 16;
    };
}
