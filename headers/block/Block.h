#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include "texture/AssetManager.h"

namespace mb {
    class Block {
    public:
        enum class Type {
            Dirt = 2,
            Grass = 3
        };
        static const int SIZE = 16;

        explicit Block(sf::Vector2i position, Type type, const AssetManager &assetsManager);

        [[nodiscard]] sf::Vector2i getPosition() const noexcept;

        [[nodiscard]] const sf::IntRect &getTextureRect() const;

        [[nodiscard]] Type getType() const noexcept;

    private:
        sf::Vector2i position;
        Type type{};
        sf::IntRect textureRect{};
    };
}
