#ifndef VECTOR3_H
#define VECTOR3_H

namespace Graphics
{
    namespace Vectors
    {
        template <typename T>
        class Vec3
        {
        public:
            Vec3();
            Vec3(T x, T y, T z);
            T Length() const;

            T operator[](int i) const;
            T &operator[](int i);

            Vec3 &operator+=(const Vec3 &other);
            Vec3 &operator-=(const Vec3 &other);
            Vec3 &operator*=(const T scalar);
            Vec3 &operator/=(const T scalar);

            Vec3 operator+(const Vec3 &other) const;
            Vec3 operator-(const Vec3 &other) const;
            Vec3 operator*(const T scalar) const;
            Vec3 operator/(const T scalar) const;

            T X, Y, Z;
        };
    }
}


template <typename T>
inline Graphics::Vectors::Vec3<T>::Vec3()
{
}

template <typename T>
inline Graphics::Vectors::Vec3<T>::Vec3(T x, T y, T z) : X(x), Y(y), Z(z)
{
}


template <typename T>
inline T Graphics::Vectors::Vec3<T>::Length() const
{
    return std::sqrt(X*X + Y*Y + Z*Z);
}


template <typename T>
inline T Graphics::Vectors::Vec3<T>::operator[](int i) const
{
    switch (i)
    {
        case 0: return X;
        case 1: return Y;
        default: return Z;
    }
}

template <typename T>
inline T &Graphics::Vectors::Vec3<T>::operator[](int i)
{
    switch (i)
    {
        case 0: return X;
        case 1: return Y;
        default: return Z;
    }
}


template <typename T>
inline Graphics::Vectors::Vec3<T> &Graphics::Vectors::Vec3<T>::operator+=(const Vec3 &other)
{
    X += other.X;
    Y += other.Y;
    Z += other.Z;
    return *this;
}

template <typename T>
inline Graphics::Vectors::Vec3<T> &Graphics::Vectors::Vec3<T>::operator-=(const Vec3 &other)
{
    X -= other.X;
    Y -= other.Y;
    Z -= other.Z;
    return *this;
}

template <typename T>
inline Graphics::Vectors::Vec3<T> &Graphics::Vectors::Vec3<T>::operator*=(T scalar)
{
    X *= scalar;
    Y *= scalar;
    Z *= scalar;
    return *this;
}

template <typename T>
inline Graphics::Vectors::Vec3<T> &Graphics::Vectors::Vec3<T>::operator/=(T scalar)
{
    X /= scalar;
    Y /= scalar;
    Z /= scalar;
    return *this;
}


template <typename T>
inline Graphics::Vectors::Vec3<T> Graphics::Vectors::Vec3<T>::operator+(const Vec3<T> &other) const
{
    return Graphics::Vectors::Vec3<T>(X + other.X, Y + other.Y, Z + other.Z);
}

template <typename T>
inline Graphics::Vectors::Vec3<T> Graphics::Vectors::Vec3<T>::operator-(const Vec3<T> &other) const
{
    return Graphics::Vectors::Vec3<T>(X - other.X, Y - other.Y, Z - other.Z);
}

template <typename T>
inline Graphics::Vectors::Vec3<T> Graphics::Vectors::Vec3<T>::operator*(T scalar) const
{
    return Graphics::Vectors::Vec3<T>(X * scalar, Y * scalar, Z * scalar);
}

template <typename T>
inline Graphics::Vectors::Vec3<T> Graphics::Vectors::Vec3<T>::operator/(T scalar) const
{
    return Graphics::Vectors::Vec3<T>(X / scalar, Y / scalar, Z / scalar);
}


#define Vec3i Vec3<int>
#define Vec3f Vec3<float>
#define Vec3d Vec3<double>

#endif
