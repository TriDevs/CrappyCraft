#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "Texture.h"
#include <unordered_map>

class TextureManager
{
public:
    static Graphics::Textures::Texture &Get(std::string tex);

private:
    static std::unordered_map<std::string, Graphics::Textures::Texture> msTextures;
};

#endif
