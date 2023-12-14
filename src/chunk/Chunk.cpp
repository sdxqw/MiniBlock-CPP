#include "chunk/Chunk.h"

namespace mb {
    Chunk::Chunk(sf::Vector2i position) : position(position) {
        blocks.resize(Chunk::SIZE * Chunk::SIZE);
        int startX = getPosition().x;
        int startY = getPosition().y;

        for (int i = 0; i < Chunk::SIZE; ++i) {
            for (int j = 0; j < Chunk::SIZE; ++j) {
                blocks[i * Chunk::SIZE + j] = Block(sf::Vector2i(startX + i * Block::SIZE, startY + j * Block::SIZE));
            }
        }
    }

    void Chunk::render(sf::RenderWindow &window) const {
        for (int i = 0; i < Chunk::SIZE; ++i) {
            for (int j = 0; j < Chunk::SIZE; ++j) {
                window.draw(blocks[i * Chunk::SIZE + j].getShape());
            }
        }
    }

    sf::Vector2i Chunk::getPosition() const noexcept {
        return position;
    }

    Block& Chunk::at(int x, int y) {
        return blocks[x * Chunk::SIZE + y];
    }

    const Block& Chunk::at(int x, int y) const {
        return blocks[x * Chunk::SIZE + y];
    }
}