#ifndef VECTOR2_H
#define VECTOR2_H

template <typename T>
class Vec2
{
public:
	Vec2();
	Vec2(T x, T y);
	T Length() const;

	T operator[](int i) const;
	T &operator[](int i);

	void operator+=(const Vec2 &other);
	void operator-=(const Vec2 &other);
	void operator*=(const T scalar);
	void operator/=(const T scalar);

	Vec2 operator+(const Vec2 &other) const;
	Vec2 operator-(const Vec2 &other) const;
	Vec2 operator*(const T scalar) const;
	Vec2 operator/(const T scalar) const;

	T X, Y;
};


template <typename T>
inline Vec2<T>::Vec2()
{
}

template <typename T>
inline Vec2<T>::Vec2(T x, T y) : X(x), Y(y)
{
}


template <typename T>
inline T Vec2<T>::Length() const
{
	return std::sqrt(X*X + Y*Y);
}


template <typename T>
inline T Vec2<T>::operator[](int i) const
{
	return i ? Y : X;
}

template <typename T>
inline T &Vec2<T>::operator[](int i)
{
	return i ? y : x;
}


template <typename T>
inline void Vec2<T>::operator+=(const Vec2 &other)
{
	x += other.x;
	y += other.y;
}

template <typename T>
inline void Vec2<T>::operator-=(const Vec2 &other)
{
	x -= other.x;
	y -= other.y;
}

template <typename T>
inline void Vec2<T>::operator*=(const T scalar)
{
	x *= scalar;
	y *= scalar;
}

template <typename T>
inline void Vec2<T>::operator/=(const T scalar)
{
	x /= scalar;
	y /= scalar;
}


template <typename T>
inline Vec2<T> Vec2<T>::operator+(const Vec2 &other) const
{
	return Vec2<T>(x + other.x, y + other.y);
}

template <typename T>
inline Vec2<T> Vec2<T>::operator-(const Vec2 &other) const
{
	return Vec2<T>(x - other.x, y - other.y);
}

template <typename T>
inline Vec2<T> Vec2<T>::operator*(const T scalar) const
{
	return Vec2<T>(x * scalar, y * scalar);
}

template <typename T>
inline Vec2<T> Vec2<T>::operator/(const T scalar) const
{
	return Vec2(x / scalar, y / scalar);
}


#define Vec2i Vec2<int>
#define Vec2f Vec2<float>
#define Vec2d Vec2<double>

#endif