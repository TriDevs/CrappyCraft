#ifndef VECTOR4_H
#define VECTOR4_H

template <typename T>
class Vec4
{
public:
    Vec4();
    Vec4(T x, T y, T z, T w);
    T Length() const;

    T operator[](int i) const;
    T &operator[](int i);

    Vec4 &operator+=(const Vec4 &other);
    Vec4 &operator-=(const Vec4 &other);
    Vec4 &operator*=(const T scalar);
    Vec4 &operator/=(const T scalar);

    Vec4 operator+(const Vec4 &other) const;
    Vec4 operator-(const Vec4 &other) const;
    Vec4 operator*(const T scalar) const;
    Vec4 operator/(const T scalar) const;

    T X, Y, Z, W;
};


template <typename T>
inline Vec4<T>::Vec4()
{
}

template <typename T>
inline Vec4<T>::Vec4(T x, T y, T z, T w) : X(x), Y(y), Z(z), W(w)
{
}


template <typename T>
inline T Vec4<T>::Length() const
{
    return std::sqrt(X*X + Y*Y + Z*Z + W*W);
}


template <typename T>
inline T Vec4<T>::operator[](int i) const
{
    switch (i)
    {
        case 0: return X;
        case 1: return Y;
        case 2: return Z;
        default: return W;
    }
}

template <typename T>
inline T &Vec4<T>::operator[](int i)
{
    switch (i)
    {
        case 0: return X;
        case 1: return Y;
        case 2: return Z;
        default: return W;
    }
}


template <typename T>
inline Vec4<T> &Vec4<T>::operator+=(const Vec4 &other)
{
    X += other.X;
    Y += other.Y;
    Z += other.Z;
    W += other.W;
    return *this;
}

template <typename T>
inline Vec4<T> &Vec4<T>::operator-=(const Vec4 &other)
{
    X -= other.X;
    Y -= other.Y;
    Z -= other.Z;
    W -= other.W;
    return *this;
}

template <typename T>
inline Vec4<T> &Vec4<T>::operator*=(const T scalar)
{
    X *= scalar;
    Y *= scalar;
    Z *= scalar;
    W *= scalar;
    return *this;
}

template <typename T>
inline Vec4<T> &Vec4<T>::operator/=(const T scalar)
{
    X /= scalar;
    Y /= scalar;
    Z /= scalar;
    W /= scalar;
    return *this;
}


template <typename T>
inline Vec4<T> Vec4<T>::operator+(const Vec4<T> &other) const
{
    return Vec4<T>(X + other.X, Y + other.Y, Z + other.Z, W + other.W);
}

template <typename T>
inline Vec4<T> Vec4<T>::operator-(const Vec4<T> &other) const
{
    return Vec4<T>(X - other.X, Y - other.Y, Z - other.Z, W - other.W);
}

template <typename T>
inline Vec4<T> Vec4<T>::operator*(T scalar) const
{
    return Vec4<T>(X * scalar, Y * scalar, Z * scalar, W * scalar);
}

template <typename T>
inline Vec4<T> Vec4<T>::operator/(T scalar) const
{
    return Vec4<T>(X / scalar, Y / scalar, Z / scalar, W / scalar);
}

typedef Vec4<int> Vec4i;
typedef Vec4<float> Vec4f;
typedef Vec4<double> Vec4d;

#endif