#include "texture/TextureAtlas.h"
#include <iostream>

namespace mb {
    TextureAtlas::TextureAtlas(const std::string &atlasPath, int spriteSize) {
        if (!atlasTexture.loadFromFile(atlasPath)) {
            throw std::runtime_error("Could not load texture atlas");
        }

        textureRects[0] = sf::IntRect(0, 0, spriteSize, spriteSize);
        textureRects[1] = sf::IntRect(spriteSize, 0, spriteSize, spriteSize);
    }

    const sf::IntRect &TextureAtlas::getTextureRect(int index) const {
        if (textureRects.find(index) != textureRects.end()) {
            return textureRects.at(index);
        } else {
            throw std::out_of_range("Index does not exist in textureRects");
        }
    }

    const sf::Texture &TextureAtlas::getTexture() const noexcept {
        return atlasTexture;
    }
}