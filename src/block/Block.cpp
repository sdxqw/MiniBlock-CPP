#include "block/Block.h"

namespace mb {

    Block::Block(sf::Vector2i position, Type type, const AssetManager &assetsManager)
            : position(position),
              type(type),
              textureRect(assetsManager.getTextureAtlas().getTextureRect(0)) {
    }

    sf::Vector2i Block::getPosition() const noexcept {
        return position;
    }

    Block::Type Block::getType() const noexcept {
        return type;
    }

    const sf::IntRect &Block::getTextureRect() const {
        return textureRect;
    }
}