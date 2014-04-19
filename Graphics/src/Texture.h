#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

class Texture
{
public:
	Texture();
	Texture(const std::string &path);
	~Texture();

private:
	unsigned int mTexID;
};

#endif
