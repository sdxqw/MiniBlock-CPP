#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>

namespace mb {
    class Block {
    private:
        int x;
        int y;
        sf::RectangleShape shape;
    public:

        Block(int x, int y) : x(x), y(y) {};
        ~Block() noexcept = default;

        void create();

        [[nodiscard]] int getX() const noexcept;

        [[nodiscard]] int getY() const noexcept;

        const sf::RectangleShape &getShape() const;
    };
}
