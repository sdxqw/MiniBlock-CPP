#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "texture/AssetManager.h"
#include "texture/TextureAtlas.h"

namespace mb {
    class Block {
    public:
        static const int SIZE = 16;

        explicit Block(sf::Vector2i position, TextureAtlas::Type type, const AssetManager &assetsManager);

        [[nodiscard]] sf::Vector2i getPosition() const noexcept;

        [[nodiscard]] const sf::IntRect &getTextureRect() const;

        [[nodiscard]] TextureAtlas::Type getType() const noexcept;

    private:
        sf::Vector2i position;
        TextureAtlas::Type type{};
        sf::IntRect textureRect{};
    };
}
