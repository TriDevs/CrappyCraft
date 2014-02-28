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

	T x, y, z;
};

#define Vec3i Vec3<int>
#define Vec3f Vec3<float>
#define Vec3d Vec3<double>

#endif