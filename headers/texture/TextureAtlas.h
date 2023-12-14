#pragma once

#include <SFML/Graphics.hpp>
#include <map>

namespace mb {
    class TextureAtlas {
    private:
        sf::Texture atlasTexture;
        std::map<int, sf::IntRect> textureRects;
    public:
        TextureAtlas(const std::string &atlasPath, int spriteSize);

        const sf::IntRect &getTextureRect(int index) const;

        const sf::Texture &getTexture() const noexcept;
    };
}