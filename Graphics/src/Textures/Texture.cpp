#include "Texture.h"
#include "../Log.h"
#include <SOIL.h>
#include <GLFW/glfw3.h>

Graphics::Textures::Texture::Texture()
{
}

Graphics::Textures::Texture::Texture(const std::string &path)
{
    mTexID = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0);
    LOG_DEBUG("Texture #" + m_TexID + " created: " + path)
}

Graphics::Textures::Texture::~Texture()
{
    if (mTexID)
    {
        glDeleteTextures(1, &mTexID);
        LOG_DEBUG("Texture #" + mTexID + " destroyed")
    }
}
