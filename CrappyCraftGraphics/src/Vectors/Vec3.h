#ifndef VECTOR2_H
#define VECTOR2_H

template <class T>
class Vec3
{
public:
	Vec3();
	Vec3(T x, T y, T z);
	T Length() const;

	T operator[](int i) const;
	T &operator[](int i);

	void operator+=(const Vec3 &other);
	void operator-=(const Vec3 &other);
	void operator*=(const T scalar);
	void operator/=(const T scalar);

	Vec3 operator+(const Vec3 &other) const;
	Vec3 operator-(const Vec3 &other) const;
	Vec3 operator*(const T scalar) const;
	Vec3 operator/(const T scalar) const;

	T X, Y, Z;
};


template <class T>
inline Vec3<T>::Vec3()
{
}

template <class T>
inline Vec3<T>::Vec3(T x, T y, T z) : x(x), y(y), z(z)
{
}


template <class T>
inline T Vec3<T>::Length() const
{
	return std::sqrt(X*X + Y*Y + Z*Z);
}


template <class T>
inline T Vec3<T>::operator[](int i) const
{
	return{ X, Y, Z }[i];
}

template <class T>
inline T &Vec3<T>::operator[](int i)
{
	return{ x, y, z }[i];
}


template <class T>
inline void Vec3<T>::operator+=(const Vec3 &other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}

template <class T>
inline void Vec3<T>::operator-=(const Vec3 &other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
}

template <class T>
inline void Vec3<T>::operator*=(T scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

template <class T>
inline void Vec3<T>::operator/=(T scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
}


template <class T>
inline Vec3<T> Vec3<T>::operator+(const Vec3 &other) const
{
	return Vec3<T>(x + other.x, y + other.y, z + other.z);
}

template <class T>
inline Vec3<T> Vec3<T>::operator-(const Vec3 &other) const
{
	return Vec3<T>(x - other.x, y - other.y, z - other.z);
}

template <class T>
inline Vec3<T> Vec3<T>::operator*(T scalar) const
{
	return Vec3<T>(x * scalar, y * scalar, z * scalar);
}

template <class T>
inline Vec3<T> Vec3<T>::operator/(T scalar) const
{
	return Vec3<T>(x / scalar, y / scalar, z / scalar);
}


#define Vec3i Vec3<int>
#define Vec3f Vec3<float>
#define Vec3d Vec3<double>

#endif