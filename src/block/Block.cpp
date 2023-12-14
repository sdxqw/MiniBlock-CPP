#include <random>
#include "block/Block.h"

namespace mb {
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
                static_cast<float>(getPosition().x),
                static_cast<float>(getPosition().y)));
    }

    sf::Vector2i Block::getPosition() const noexcept {
        return position;
    }

    Block::Type Block::getType() const noexcept {
        return type;
    }
}