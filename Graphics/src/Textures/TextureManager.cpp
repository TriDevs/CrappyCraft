#include "TextureManager.h"
#include <algorithm>

Texture &TextureManager::Get(std::string tex)
{
    Texture &texture = msTextures[tex];

    // Load the texture if it doesn't exist
    if (!texture.IsLoaded())
    {
        std::replace(tex.begin(), tex.end(), '.', '/');
        texture = Texture("assets/" + tex);
    }

    // Return it
    return texture;
}
