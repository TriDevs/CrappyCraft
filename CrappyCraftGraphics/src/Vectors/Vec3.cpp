#include "Vec3.h"

template <class T>
Vec3<T>::Vec3()
{
}

template <class T>
Vec3<T>::Vec3(T x, T y, T z) : x(x), y(y), z(z)
{
}


template <class T>
T Vec3<T>::Length() const
{
	return std::sqrt(x*x + y*y + z*z);
}


template <class T>
T Vec3<T>::operator[](int i) const
{
	return { x, y, z }[i];
}

template <class T>
T &Vec3<T>::operator[](int i)
{
	return { x, y, z }[i];
}


template <class T>
void Vec3<T>::operator+=(const Vec3 &other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}

template <class T>
void Vec3<T>::operator-=(const Vec3 &other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
}

template <class T>
void Vec3<T>::operator*=(T scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

template <class T>
void Vec3<T>::operator/=(T scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
}


template <class T>
Vec3<T> Vec3<T>::operator+(const Vec3 &other) const
{
	return Vec3<T>(x + other.x, y + other.y, z + other.z);
}

template <class T>
Vec3<T> Vec3<T>::operator-(const Vec3 &other) const
{
	return Vec3<T>(x - other.x, y - other.y, z - other.z);
}

template <class T>
Vec3<T> Vec3<T>::operator*(T scalar) const
{
	return Vec3<T>(x * scalar, y * scalar, z * scalar);
}

template <class T>
Vec3<T> Vec3<T>::operator/(T scalar) const
{
	return Vec3<T>(x / scalar, y / scalar, z / scalar);
}