#ifndef MAT4_H
#define MAT4_H
#include "Vec4.h"

namespace Graphics
{
    namespace Vectors
    {
        template <typename T>
        class Mat4
        {
        public:
            Mat4();
            Mat4(Vec4<Vec4<T>> matrix);
            Mat4(Vec4<T> abcd, Vec4<T> efgh, Vec4<T> ijkl, Vec4<T> mnop);
            Mat4(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p);

            Vec4<T> operator[](int i) const;
            Vec4<T> &operator[](int i);

            Mat4 &operator+=(const Mat4<T> &other);
            Mat4 &operator-=(const Mat4<T> &other);
            Mat4 &operator*=(const T scalar);
            Mat4 &operator/=(const T scalar);

            Mat4 operator+(const Mat4 &other) const;
            Mat4 operator-(const Mat4 &other) const;
            Mat4 operator*(const T scalar) const;
            Mat4 operator/(const T scalar) const;
            Vec4<T> operator*(const Vec4<T> &vec) const;
            Vec4<T> operator/(const Vec4<T> &vec) const;

            Vec4<Vec4<T>> mMatrix;
        };
    }
}

template <typename T>
inline Graphics::Vectors::Mat4<T>::Mat4()
{
}

template <typename T>
inline Graphics::Vectors::Mat4<T>::Mat4(Vec4<Vec4<T>> matrix)
    : mMatrix(matrix)
{
}

template <typename T>
inline Graphics::Vectors::Mat4<T>::Mat4(Vec4<T> abcd, Vec4<T> efgh, Vec4<T> ijkl, Vec4<T> mnop)
    : mMatrix(abcd, efgh, ijkl, mnop)
{
}

template <typename T>
inline Graphics::Vectors::Mat4<T>::Mat4(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p)
    : mMatrix(Vec4<T>(a, b, c, d), Vec4<T>(e, f, g, h), Vec4<T>(i, j, k, l), Vec4<T>(m, n, o, p))
{
}


template <typename T>
inline Graphics::Vectors::Mat4<T> &Graphics::Vectors::Mat4<T>::operator+=(const Mat4<T> &other)
{
    mMatrix += other.mMatrix;
    return *this;
}

template <typename T>
inline Graphics::Vectors::Mat4<T> &Graphics::Vectors::Mat4<T>::operator-=(const Mat4<T> &other)
{
    mMatrix -= other.mMatrix;
    return *this;
}

template <typename T>
inline Graphics::Vectors::Mat4<T> &Graphics::Vectors::Mat4<T>::operator*=(const T scalar)
{
    for (int i = 0; i < 4; i++)
        mMatrix[i] *= scalar;
    return *this;
}

template <typename T>
inline Graphics::Vectors::Mat4<T> &Graphics::Vectors::Mat4<T>::operator/=(const T scalar)
{
    for (int i = 0; i < 4; i++)
        mMatrix[i] /= scalar;
    return *this;
}

template <typename T>
inline Graphics::Vectors::Mat4<T> Graphics::Vectors::Mat4<T>::operator+(const Mat4<T> &other) const
{
    return Mat4(mMatrix + other.mMatrix);
}

template <typename T>
inline Graphics::Vectors::Mat4<T> Graphics::Vectors::Mat4<T>::operator-(const Mat4<T> &other) const
{
    return Mat4(mMatrix - other.mMatrix);
}

template <typename T>
inline Graphics::Vectors::Mat4<T> Graphics::Vectors::Mat4<T>::operator*(const T scalar) const
{
    return Mat4(mMatrix * scalar);
}

template <typename T>
inline Graphics::Vectors::Mat4<T> Graphics::Vectors::Mat4<T>::operator/(const T scalar) const
{
    return Mat4(mMatrix / scalar);
}

template <typename T>
inline Graphics::Vectors::Vec4<T> Graphics::Vectors::Mat4<T>::operator*(const Vec4<T> &vec) const
{
    Vec4<T> v;
    for (int i = 0; i < 4; i++)
        v[i] = mMatrix[i][0] * vec[0] + mMatrix[i][1] * vec[1] +
            mMatrix[i][2] * vec[2] + mMatrix[i][3] * vec[3];
    return v;
}

template <typename T>
inline Graphics::Vectors::Vec4<T> Graphics::Vectors::Mat4<T>::operator/(const Vec4<T> &vec) const
{
    Vec4<T> v;
    for (int i = 0; i < 4; i++)
        v[i] = mMatrix[i][0] / vec[0] + mMatrix[i][1] / vec[1] +
            mMatrix[i][2] / vec[2] + mMatrix[i][3] / vec[3];
    return v;
}

template <typename T>
inline Graphics::Vectors::Mat4<T> Graphics::Vectors::Mat4<T>::operator*(const Mat4<T> &mat) const
{
    Mat4<T> m;
    for (int iRow = 0; iRow < 3; iRow++)
    {
        for (int iColumn = 0; iColumn < 3; iColumn++)
        {
            m[iRow][iColumn] = mMatrix[iRow][0] * mat[0][iColumn] +
                mMatrix[iRow][1] * mat[1][iColumn] + mMatrix[iRow][2] * mat[2][iColumn];
        }
    }
    return m;
}

template <typename T>
inline Graphics::Vectors::Mat4<T> Graphics::Vectors::Mat4<T>::operator/(const Mat4<T> &mat) const
{
    Mat4<T> m;
    for (int iRow = 0; iRow < 3; iRow++)
    {
        for (int iColumn = 0; iColumn < 3; iColumn++)
        {
            m[iRow][iColumn] = mMatrix[iRow][0] / mat[0][iColumn] +
                mMatrix[iRow][1] / mat[1][iColumn] + mMatrix[iRow][2] / mat[2][iColumn];
        }
    }
    return m;
}

template <typename T>
inline Graphics::Vectors::Vec4<T> Graphics::Vectors::Mat4<T>::operator[](int i) const
{
    return mMatrix[i];
}

template <typename T>
inline Graphics::Vectors::Vec4<T> &Graphics::Vectors::Mat4<T>::operator[](int i)
{
    return mMatrix[i];
}

typedef Graphics::Vectors::Mat4<int> Graphics::Vectors::Mat4i;
typedef Graphics::Vectors::Mat4<float> Graphics::Vectors::Mat4f;
typedef Graphics::Vectors::Mat4<double> Graphics::Vectors::Mat4d;

#endif
