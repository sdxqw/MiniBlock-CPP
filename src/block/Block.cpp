#include "block/Block.h"
#include "texture/AssetManager.h"
#include "texture/TextureAtlas.h"

namespace mb {
    sf::Vector2i Block::getPosition() const noexcept {
        return position;
    }

    const sf::IntRect &Block::getTextureRect() const {
        return textureRect;
    }

    Block::Block(sf::Vector2i position, TextureAtlas::Type type, const AssetManager &assetsManager)
            : position(position),
              type(type),
              textureRect(assetsManager.getTextureAtlas().getTextureRect(type)) {}

    TextureAtlas::Type Block::getType() const noexcept {
        return type;
    }
}