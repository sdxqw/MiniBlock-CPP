#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "block/Block.h"

namespace mb {
    class Chunk {
    private:
        sf::Vector2i position;
        std::vector<Block> blocks;
        AssetManager &assetsManager;
    public:
        explicit Chunk(sf::Vector2i position, AssetManager &assetManager);

        [[nodiscard]] sf::Vector2i getPosition() const noexcept;

        void render(sf::RenderWindow &window) const;

        std::vector<Block>::reference get(sf::Vector2i pos);

        static const int SIZE = 16;
    };
}
