#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

namespace Graphics
{
    namespace Textures
    {
        class Texture
        {
        public:
            Texture();
            Texture(const std::string &path);
            ~Texture();

            bool IsLoaded() const { return mTexID; };

        private:
            unsigned int mTexID;
        };
    }
}

#endif
