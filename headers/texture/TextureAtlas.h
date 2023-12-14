#pragma once

#include <SFML/Graphics.hpp>
#include <map>

namespace mb {
    class TextureAtlas {
    private:
        sf::Texture atlasTexture;
        std::map<int, sf::IntRect> textureRects;
        int spriteSize;

    public:
        TextureAtlas(const std::string &atlasPath, int spriteSize);

        sf::Sprite getSprite(int index) const;
    };
}