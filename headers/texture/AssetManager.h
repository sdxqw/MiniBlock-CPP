#pragma once
#include "TextureAtlas.h"

namespace mb {
    class AssetManager {
    private:
        TextureAtlas textureAtlas;
    public:

        AssetManager(const std::string &atlasPath, int spriteSize);

        [[nodiscard]] TextureAtlas getTextureAtlas() const;
    };
}