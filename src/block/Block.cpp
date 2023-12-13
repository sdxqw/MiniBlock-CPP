#include <random>
#include "block/Block.h"

namespace mb {
    int Block::getX() const noexcept {
        return position.x;
    }

    int Block::getY() const noexcept {
        return position.y;
    }

    const sf::RectangleShape &Block::getShape() const {
        return shape;
    }

    Block::Block(sf::Vector2i position) : position(position) {
        shape.setSize(sf::Vector2f(Block::SIZE, Block::SIZE));
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<sf::Uint8> dist(0, 255);
        shape.setFillColor(sf::Color(dist(mt), dist(mt), dist(mt)));
        shape.setPosition(sf::Vector2f(
                static_cast<float>(getX()),
                static_cast<float>(getY())));
    }
}