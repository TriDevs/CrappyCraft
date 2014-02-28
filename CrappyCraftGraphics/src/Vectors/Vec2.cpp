#include "Vec2.h"

template <class T>
Vec2<T>::Vec2()
{
}

template <class T>
Vec2<T>::Vec2(T x, T y) : x(x), y(y)
{
}


template <class T>
T Vec2<T>::Length() const
{
	return std::sqrt(x*x + y*y);
}


template <class T>
T Vec2<T>::operator[](int i) const
{
	return i ? y : x;
}

template <class T>
T &Vec2<T>::operator[](int i)
{
	return i ? y : x;
}


template <class T>
void Vec2<T>::operator+=(const Vec2 &other)
{
	x += other.x;
	y += other.y;
}

template <class T>
void Vec2<T>::operator-=(const Vec2 &other)
{
	x -= other.x;
	y -= other.y;
}

template <class T>
void Vec2<T>::operator*=(const T scalar)
{
	x *= scalar;
	y *= scalar;
}

template <class T>
void Vec2<T>::operator/=(const T scalar)
{
	x /= scalar;
	y /= scalar;
}


template <class T>
Vec2<T> Vec2<T>::operator+(const Vec2 &other) const
{
	return Vec2<T>(x + other.x, y + other.y);
}

template <class T>
Vec2<T> Vec2<T>::operator-(const Vec2 &other) const
{
	return Vec2<T>(x - other.x, y - other.y);
}

template <class T>
Vec2<T> Vec2<T>::operator*(const T scalar) const
{
	return Vec2<T>(x * scalar, y * scalar);
}

template <class T>
Vec2<T> Vec2<T>::operator/(const T scalar) const
{
	return Vec2(x / scalar, y / scalar);
}