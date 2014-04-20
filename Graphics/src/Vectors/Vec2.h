#ifndef VECTOR2_H
#define VECTOR2_H
#include <cmath>

namespace Graphics
{
    namespace Vectors
    {
        template <typename T>
        class Vec2
        {
        public:
            Vec2();
            Vec2(T x, T y);
            T Length() const;

            T operator[](int i) const;
            T &operator[](int i);

            Vec2 &operator+=(const Vec2 &other);
            Vec2 &operator-=(const Vec2 &other);
            Vec2 &operator*=(const T scalar);
            Vec2 &operator/=(const T scalar);

            Vec2 operator+(const Vec2 &other) const;
            Vec2 operator-(const Vec2 &other) const;
            Vec2 operator*(const T scalar) const;
            Vec2 operator/(const T scalar) const;

            T X, Y;
        };

        typedef Vec2<int> Vec2i;
        typedef Vec2<float> Vec2f;
        typedef Vec2<double> Vec2d;
    }
}

template <typename T>
inline Graphics::Vectors::Vec2<T>::Vec2()
{
}

template <typename T>
inline Graphics::Vectors::Vec2<T>::Vec2(T x, T y) : X(x), Y(y)
{
}


template <typename T>
inline T Graphics::Vectors::Vec2<T>::Length() const
{
    return std::sqrt(X*X + Y*Y);
}


template <typename T>
inline T Graphics::Vectors::Vec2<T>::operator[](int i) const
{
    return i ? Y : X;
}

template <typename T>
inline T &Graphics::Vectors::Vec2<T>::operator[](int i)
{
    return i ? Y : X;
}


template <typename T>
inline Graphics::Vectors::Vec2<T> &Graphics::Vectors::Vec2<T>::operator+=(const Vec2 &other)
{
    X += other.x;
    Y += other.y;
    return *this;
}

template <typename T>
inline Graphics::Vectors::Vec2<T> &Graphics::Vectors::Vec2<T>::operator-=(const Vec2 &other)
{
    X -= other.x;
    Y -= other.y;
    return *this;
}

template <typename T>
inline Graphics::Vectors::Vec2<T> &Graphics::Vectors::Vec2<T>::operator*=(const T scalar)
{
    X *= scalar;
    Y *= scalar;
    return *this;
}

template <typename T>
inline Graphics::Vectors::Vec2<T> &Graphics::Vectors::Vec2<T>::operator/=(const T scalar)
{
    X /= scalar;
    Y /= scalar;
    return *this;
}


template <typename T>
inline Graphics::Vectors::Vec2<T> Graphics::Vectors::Vec2<T>::operator+(const Vec2 &other) const
{
    return Graphics::Vectors::Vec2<T>(X + other.X, Y + other.Y);
}

template <typename T>
inline Graphics::Vectors::Vec2<T> Graphics::Vectors::Vec2<T>::operator-(const Vec2 &other) const
{
    return Graphics::Vectors::Vec2<T>(X - other.X, Y - other.Y);
}

template <typename T>
inline Graphics::Vectors::Vec2<T> Graphics::Vectors::Vec2<T>::operator*(const T scalar) const
{
    return Graphics::Vectors::Vec2<T>(X * scalar, Y * scalar);
}

template <typename T>
inline Graphics::Vectors::Vec2<T> Graphics::Vectors::Vec2<T>::operator/(const T scalar) const
{
    return Graphics::Vectors::Vec2<T>(X / scalar, Y / scalar);
}

#endif
