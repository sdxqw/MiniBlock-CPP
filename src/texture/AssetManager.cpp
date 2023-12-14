#include "texture/AssetManager.h"

namespace mb {
    AssetManager::AssetManager(const std::string& atlasPath, int spriteSize)
            : textureAtlas(atlasPath, spriteSize) {}

    const TextureAtlas& AssetManager::getTextureAtlas() const {
        return textureAtlas;
    }
}