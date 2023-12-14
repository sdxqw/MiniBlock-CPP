#include "texture/AssetManager.h"

namespace mb {
    AssetManager::AssetManager(const std::string &atlasPath, int spriteSize)
            : textureAtlas(atlasPath, spriteSize) {}

    TextureAtlas AssetManager::getTextureAtlas() const {
        return textureAtlas;
    }
}