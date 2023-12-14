#include "chunk/Chunk.h"

namespace mb {
    Chunk::Chunk(sf::Vector2i position, AssetManager &assetManager) : position(position), assetsManager(assetManager) {
        int startX = getPosition().x;
        int startY = getPosition().y;

        for (int i = 0; i < Chunk::SIZE; ++i) {
            for (int j = 0; j < Chunk::SIZE; ++j) {
                blocks.emplace_back(sf::Vector2i(startX + i * Block::SIZE, startY + j * Block::SIZE), Block::Type::Dirt,
                                    assetsManager);
            }
        }
    }

    void Chunk::render(sf::RenderWindow &window) const {
        sf::Sprite sprite;
        sprite.setTexture(assetsManager.getTextureAtlas().getTexture());
        for (int i = 0; i < Chunk::SIZE; ++i) {
            for (int j = 0; j < Chunk::SIZE; ++j) {
                sprite.setTextureRect(blocks[i * Chunk::SIZE + j].getTextureRect());
                sprite.setPosition(static_cast<float>(i * Block::SIZE), static_cast<float>(j * Block::SIZE));
                window.draw(sprite);
            }
        }
    }

    sf::Vector2i Chunk::getPosition() const noexcept {
        return position;
    }

    Block &Chunk::at(int x, int y) {
        return blocks[x * Chunk::SIZE + y];
    }
}