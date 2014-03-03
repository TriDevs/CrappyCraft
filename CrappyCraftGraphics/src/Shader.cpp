#include "Shader.h"
#include <gl/glew.h>
#include <fstream>

Graphics::Shader::Shader()
{
}

Graphics::Shader::Shader(int shaderType)
    : mShaderID(glCreateShader(shaderType))
{
}

Graphics::Shader::Shader(int shaderType, std::string path)
    : mShaderID(glCreateShader(shaderType))
{
    // Read the source code from the file
    std::ifstream ifs(path);
    if (!ifs.is_open()) throw std::runtime_error("Error opening shader " + path);
    std::string source((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    ifs.close();

    // Compile the shader
    const char *sourcePtr = source.c_str();
    glShaderSource(mShaderID, 1, &sourcePtr, NULL);
    glCompileShader(mShaderID);

    // Check the results
    int result;
    glGetShaderiv(mShaderID, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        int logLength;
        glGetShaderiv(mShaderID, GL_INFO_LOG_LENGTH, &logLength);
        char *log = new char[logLength];
        glGetShaderInfoLog(mShaderID, logLength, NULL, log);
        throw std::runtime_error("Error compiling shader " + path + ":\n" + log);
    }
}

Graphics::Shader::~Shader()
{
    glDeleteShader(mShaderID);
}

//////////////////////////////////////////////////////////////////////////

Graphics::ShaderProgram::ShaderProgram()
    : mProgramID(glCreateProgram())
{
}

Graphics::ShaderProgram::ShaderProgram(std::vector<Shader> shaders)
    : mProgramID(glCreateProgram())
{
    for (Shader shader : shaders)
        glAttachShader(mProgramID, shader.GetShaderID());
    glLinkProgram(mProgramID);
}

Graphics::ShaderProgram::~ShaderProgram()
{
    Unbind();
    glDeleteProgram(mProgramID);
}

void Graphics::ShaderProgram::Bind()
{
    glUseProgram(mProgramID);
}

void Graphics::ShaderProgram::Unbind()
{
    glUseProgram(0);
}