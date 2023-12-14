#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>

namespace mb {
    class Block {
    private:
        sf::Vector2i position;
        sf::RectangleShape shape;
    public:
        static const int SIZE = 50;

        explicit Block(sf::Vector2i position);

        sf::Vector2i getPosition() const noexcept;

        const sf::RectangleShape &getShape() const;
    };
}
