#include "chunk/Chunk.h"

namespace mb {
    Chunk::~Chunk() noexcept {
        this->x = 0;
        this->y = 0;
    }

    Chunk::Chunk(int x, int y) : x(x), y(y) {
        this->blocks.resize(Chunk::SIZE);
        for (auto& inner : this->blocks) {
            inner.resize(Chunk::SIZE);
        }
        this->generate();
    }

    void Chunk::generate() {
        for (int i = 0; i < Chunk::SIZE; ++i) {
            for (int j = 0; j < Chunk::SIZE; ++j) {
                this->blocks[i][j] = std::make_unique<Block>(getX() + i * 50, getY() + j * 50);
                this->blocks[i][j]->create();
            }
        }
    }

    int Chunk::getX() const noexcept {
        return this->x;
    }

    int Chunk::getY() const noexcept {
        return this->y;
    }

    void Chunk::render(sf::RenderWindow &window) const {
        for (auto & block : this->blocks) {
            for (const auto & j : block) {
                window.draw(j->getShape());
            }
        }
    }

}