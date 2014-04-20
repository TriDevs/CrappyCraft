#ifndef CONTROL_H
#define CONTROL_H
#include "../Vectors/Vec2.h"
#include "../Textures/Texture.h"
#include <string>

namespace Graphics
{
    namespace Controls
    {
        class Control
        {
        public:
            Control();

            /// <param name="id">The ID of the control, used as reference.</param>
            /// <param name="position">2D vector with the position of the control.</param>
            /// <param name="size">2D vector with the size of the control.</param>
            /// <param name="visible">Whether the control is visible.</param>
            /// <param name="enabled">Whether the control is enabled (not greyed out).</param>
            Control(int id, Graphics::Vectors::Vec2d position, Graphics::Vectors::Vec2d size, 
                bool visible = 1, bool enabled = 1);

            virtual void Render() = 0;

            /// <summary>
            ///     The ID of this control, used as reference.
            /// </summary>
            unsigned int mID;

            /// <summary>
            ///     The ID of the vertex buffer, used by OpenGL.
            /// </summary>
            unsigned int mVertexBuffer;

            /// <summary>
            ///     A 2D vector with the position of the control.
            /// </summary>
            Graphics::Vectors::Vec2d mPosition;

            /// <summary>
            ///     A 2D vector with the size of the control.
            /// </summary>
            Graphics::Vectors::Vec2d mSize;

            /// <summary>
            ///     Whether the control is visible.
            /// </summary>
            bool mVisible;

            /// <summary>
            ///     Whether the control is enabled (not greyed out).
            /// </summary>
            bool mEnabled;

            /// <summary>
            ///     The control's texture.
            /// </summary>
            Graphics::Textures::Texture mTexture;
        private:
        };
    }
}

#endif
