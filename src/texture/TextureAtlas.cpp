#include "texture/TextureAtlas.h"
#include <iostream>

namespace mb {
    TextureAtlas::TextureAtlas(const std::string &atlasPath, int spriteSize) {
        if (!atlasTexture.loadFromFile(atlasPath)) {
            throw std::invalid_argument("TextureAtlas: Could not load texture from " + atlasPath);
        }

        textureRects[static_cast<int>(TextureAtlas::Type::Dirt)] = sf::IntRect(0, 0, spriteSize, spriteSize);
        textureRects[static_cast<int>(TextureAtlas::Type::Grass)] = sf::IntRect(spriteSize, 0, spriteSize, spriteSize);
    }

    const sf::Texture &TextureAtlas::getTexture() const noexcept {
        return atlasTexture;
    }

    const sf::IntRect &TextureAtlas::getTextureRect(TextureAtlas::Type type) const {
        auto it = textureRects.find(static_cast<int>(type));
        if (it != textureRects.end()) {
            return it->second;
        } else {
            throw std::out_of_range("Type does not exist in textureRects");
        }
    }
}