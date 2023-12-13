#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "block/Block.h"

namespace mb {
    class Chunk {
    public:
        Chunk(int x, int y);

        ~Chunk() noexcept;

        [[nodiscard]] int getX() const noexcept;

        [[nodiscard]] int getY() const noexcept;

        void render(sf::RenderWindow &window) const;

        static const int SIZE = 16;

    private:
        int x;
        int y;
        std::vector<std::vector<std::unique_ptr<Block>>> blocks;

        void generate();
    };
}
