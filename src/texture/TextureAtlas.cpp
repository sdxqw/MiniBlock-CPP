#include "texture/TextureAtlas.h"

namespace mb {
    TextureAtlas::TextureAtlas(const std::string &atlasPath, int spriteSize) : spriteSize(spriteSize) {
        atlasTexture.loadFromFile(atlasPath);
    }

    sf::Sprite TextureAtlas::getSprite(int index) const {
        unsigned int x = (index % (atlasTexture.getSize().x / spriteSize)) * spriteSize;
        unsigned int y = (index / (atlasTexture.getSize().x / spriteSize)) * spriteSize;

        sf::Sprite sprite;
        sprite.setTexture(atlasTexture);
        sprite.setTextureRect(sf::IntRect((int) x, (int) y, spriteSize, spriteSize));
        return sprite;
    }
}