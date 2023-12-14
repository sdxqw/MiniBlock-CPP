#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <unordered_map>

namespace mb {
    class TextureAtlas {
    public:
        enum class Type {
            Dirt = 2,
            Grass = 3
        };
        TextureAtlas(const std::string &atlasPath, int spriteSize);

        const sf::IntRect & getTextureRect(TextureAtlas::Type type) const;

        const sf::Texture &getTexture() const noexcept;

    private:
        sf::Texture atlasTexture;
        std::unordered_map<int, sf::IntRect> textureRects;
    };
}