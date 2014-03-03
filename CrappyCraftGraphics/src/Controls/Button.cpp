#include "Button.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Graphics::Controls::Button::Button()
{
    glGenBuffers(1, &mVertexBuffer);
}

Graphics::Controls::Button::Button(int id, Vec2d position, Vec2d size, std::string text, 
    bool visible, bool enabled) 
    : Control(id, position, size, visible, enabled), mText(text)
{
    glGenBuffers(1, &mVertexBuffer);
}

void Graphics::Controls::Button::Render()
{
    // Create a VBO
    double pVertexBufferData[] =
    {
        mPosition.X,           mPosition.Y,           0.0,
        mPosition.X + mSize.X, mPosition.Y,           0.0,
        mPosition.X + mSize.X, mPosition.Y + mSize.Y, 0.0,
        mPosition.X,           mPosition.Y + mSize.Y, 0.0
    };

    // Bind the buffer
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);

    // Send the vertices to OpenGL
    glBufferData(GL_ARRAY_BUFFER, sizeof(pVertexBufferData), pVertexBufferData, GL_STATIC_DRAW);

    // Draw the control
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_DOUBLE, false, 0, (void *)0);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableVertexAttribArray(0);
}