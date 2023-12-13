#include <random>
#include "block/Block.h"

namespace mb {
    int Block::getX() const noexcept {
        return this->x;
    }

    int Block::getY() const noexcept {
        return this->y;
    }

    void Block::create() {
        this->shape.setSize(sf::Vector2f(50, 50));
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution dist(0, 255);

        this->shape.setFillColor(sf::Color(dist(mt), dist(mt), dist(mt)));
        this->shape.setPosition(sf::Vector2f(
                static_cast<float>(this->getX()),
                static_cast<float>(this->getY())));
    }

    const sf::RectangleShape &Block::getShape() const {
        return this->shape;
    }
}