#ifndef VECTOR2_H
#define VECTOR2_H

template <class T>
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

	T x, y;
};

#define Vec2i Vec2<int>
#define Vec2f Vec2<float>
#define Vec2d Vec2<double>

#endif