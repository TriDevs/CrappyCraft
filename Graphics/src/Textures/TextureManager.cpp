#include "TextureManager.h"
#include <algorithm>

Graphics::Textures::Texture &TextureManager::Get(std::string tex)
{
    Graphics::Textures::Texture &texture = msTextures[tex];

    // Load the texture if it doesn't exist
    if (!texture.IsLoaded())
    {
        std::replace(tex.begin(), tex.end(), '.', '/');
        texture = Graphics::Textures::Texture("assets/" + tex);
    }

    // Return it
    return texture;
}
