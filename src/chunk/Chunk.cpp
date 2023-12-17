#include "chunk/Chunk.h"

namespace mb {
    Chunk::Chunk(sf::Vector2i position, AssetManager &assetManager) : position(position), assetsManager(assetManager) {
        int startX = getPosition().x;
        int startY = getPosition().y;

        for (int i = 0; i < Chunk::SIZE; ++i) {
            for (int j = 0; j < Chunk::SIZE; ++j) {
                blocks.emplace_back(sf::Vector2i(startX + i * Block::SIZE, startY + j * Block::SIZE),
                                    TextureAtlas::Type::Dirt,
                                    assetsManager);
            }
        }
    }

    void Chunk::render(sf::RenderWindow &window) const {
        sf::Sprite sprite;
        sprite.setTexture(assetsManager.getTextureAtlas().getTexture());
        for (int i = 0; i < Chunk::SIZE; ++i) {
            for (int j = 0; j < Chunk::SIZE; ++j) {
                sprite.setTextureRect(blocks.at(i * Chunk::SIZE + j).getTextureRect());
                sprite.setScale(Block::SIZE, Block::SIZE);
                sprite.setPosition(static_cast<float>(i * Block::SIZE + position.x), static_cast<float>(j * Block::SIZE + position.y));
                window.draw(sprite);
            }
        }
    }

    sf::Vector2i Chunk::getPosition() const noexcept {
        return position;
    }

    Block &Chunk::get(sf::Vector2i pos) {
        return blocks[pos.x * Chunk::SIZE + pos.y];
    }
}