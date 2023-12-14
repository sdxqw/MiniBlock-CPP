#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>

namespace mb {
    class Block {
    public:
        enum class Type {
            Dirt,
            grass
        };
        static const int SIZE = 50;

        explicit Block(sf::Vector2i position);

        sf::Vector2i getPosition() const noexcept;

        const sf::RectangleShape &getShape() const;

        Type getType() const noexcept;
    private:
        sf::Vector2i position;
        sf::RectangleShape shape;
        Type type{};
    };
}
