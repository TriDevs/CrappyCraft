#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <vector>

namespace Graphics
{
    class Shader
    {
    public:
        Shader();
        Shader(int shaderType);
        Shader(int shaderType, std::string path);
        ~Shader();

        unsigned int GetShaderID() { return mShaderID; }

    private:
        unsigned int mShaderID;
    };


    class ShaderProgram
    {
    public:
        ShaderProgram();
        ShaderProgram(std::vector<Shader> shaders);
        ~ShaderProgram();

        void Bind();
        void Unbind();

    private:
        unsigned int mProgramID;
    };
}

#endif
