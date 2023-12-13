#include "chunk/Chunk.h"

namespace mb {
    Chunk::Chunk(sf::Vector2i position) : position(position) {
        blocks.resize(Chunk::SIZE);
        int startX = getX();
        int startY = getY();

        for (int i = 0; i < Chunk::SIZE; ++i) {
            blocks[i].reserve(Chunk::SIZE);
            for (int j = 0; j < Chunk::SIZE; ++j) {
                blocks[i].emplace_back(sf::Vector2i(startX + i * Block::SIZE, startY + j * Block::SIZE));
            }
        }
    }

    int Chunk::getX() const noexcept {
        return position.x;
    }

    int Chunk::getY() const noexcept {
        return position.y;
    }

    void Chunk::render(sf::RenderWindow &window) const {
        for (auto &block: blocks) {
            for (const auto &j: block) {
                window.draw(j.getShape());
            }
        }
    }
}