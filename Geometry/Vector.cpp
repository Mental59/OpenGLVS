#include "Vector.h"
#include "Matrix.h"
#include <iostream>

#pragma region Class Vector4

template <typename T>
Vector4<T>::Vector4(T x, T y, T z, T w)
{
	this->vector[0] = x;
	this->vector[1] = y;
	this->vector[2] = z;
	this->vector[3] = w;
}

template <typename T>
Vector4<T>::Vector4(T vector[4])
{
	this->vector[0] = vector[0];
	this->vector[1] = vector[1];
	this->vector[2] = vector[2];
	this->vector[3] = vector[3];
}

template <typename T>
void Vector4<T>::show()
{
	std::cout << "Vector4(" << this->vector[0] << ", " << this->vector[1] << ", " << this->vector[2] << ", " << this->vector[3] << ")" << std::endl << std::endl;
}

template <typename T>
Vector4<T> Vector4<T>::operator +(Vector4 other)
{
	return Vector4<T>(
		this->vector[0] + other[0],
		this->vector[1] + other[1],
		this->vector[2] + other[2],
		this->vector[3] + other[3]
	);
}

template <typename T>
Vector4<T> Vector4<T>::operator -(Vector4 other)
{
	return Vector4<T>(
		this->vector[0] - other[0],
		this->vector[1] - other[1],
		this->vector[2] - other[2],
		this->vector[3] - other[3]
	);
}

template <typename T>
Vector4<T> Vector4<T>::operator *(Vector4 other)
{
	return Vector4<T>(
		this->vector[0] * other[0],
		this->vector[1] * other[1],
		this->vector[2] * other[2],
		this->vector[3] * other[3]
	);
}

template <typename T>
Vector4<T> Vector4<T>::operator *(Matrix4<T> other)
{
	T vec[4];

	for (int i = 0; i < 4; i++)
		vec[i] = this->vector[0] * other[i] +
		this->vector[1] * other[i + 4] +
		this->vector[2] * other[i + 8] +
		this->vector[3] * other[i + 12];

	return Vector4<T>(vec);
}

template <typename T>
T Vector4<T>::dot(Vector4<T> a, Vector4<T> b)
{
	Vector4<T> p = a * b;

	T res = {};

	for (int i = 0; i < 4; i++)
		res += p[i];

	return res;
}

template <typename T>
T& Vector4<T>::operator[] (const int index)
{
	return this->vector[index];
}

template <typename T>
T Vector4<T>::length()
{
	T res = {};
	for (int i = 0; i < 4; i++)
		res += vector[i] * vector[i];
	return sqrt(res);
}

template <typename T>
void Vector4<T>::normalize()
{
	T len = length();
	for (int i = 0; i < 4; i++)
		vector[i] /= len;
}

template class Vector4<float>;
template class Vector4<int>;
template class Vector4<double>;

#pragma endregion



#pragma region Class Vector3

template <typename T>
Vector3<T>::Vector3(T x, T y, T z)
{
	this->vector[0] = x;
	this->vector[1] = y;
	this->vector[2] = z;
}

template <typename T>
Vector3<T>::Vector3(T vector[3])
{
	this->vector[0] = vector[0];
	this->vector[1] = vector[1];
	this->vector[2] = vector[2];
}

template <typename T>
void Vector3<T>::show()
{
	std::cout << "Vector3(" << this->vector[0] << ", " << this->vector[1] << ", " << this->vector[2] << ")" << std::endl << std::endl;
}

template <typename T>
Vector3<T> Vector3<T>::operator +(Vector3 other)
{
	return Vector3<T>(
		this->vector[0] + other[0],
		this->vector[1] + other[1],
		this->vector[2] + other[2]
	);
}

template <typename T>
Vector3<T> Vector3<T>::operator -(Vector3 other)
{
	return Vector3<T>(
		this->vector[0] - other[0],
		this->vector[1] - other[1],
		this->vector[2] - other[2]
		);
}

template <typename T>
Vector3<T> Vector3<T>::operator *(Vector3 other)
{
	return Vector3<T>(
		this->vector[0] * other[0],
		this->vector[1] * other[1],
		this->vector[2] * other[2]
		);
}

template <typename T>
Vector3<T> Vector3<T>::operator *(Matrix3<T> other)
{
	T vec[3];

	for (int i = 0; i < 3; i++)
		vec[i] = this->vector[0] * other[i] +
		this->vector[1] * other[i + 3] +
		this->vector[2] * other[i + 6];

	return Vector3<T>(vec);
}

template <typename T>
T Vector3<T>::dot(Vector3<T> a, Vector3<T> b)
{
	Vector3<T> p = a * b;

	T res = {};

	for (int i = 0; i < 3; i++)
		res += p[i];

	return res;
}

template <typename T>
T& Vector3<T>::operator[] (const int index)
{
	return this->vector[index];
}

template <typename T>
T Vector3<T>::length()
{
	T res = {};
	for (int i = 0; i < 3; i++)
		res += vector[i] * vector[i];
	return sqrt(res);
}

template <typename T>
void Vector3<T>::normalize()
{
	T len = length();
	for (int i = 0; i < 3; i++)
		vector[i] /= len;
}

template class Vector3<float>;
template class Vector3<int>;
template class Vector3<double>;

#pragma endregion



#pragma region Class Vector2

template <typename T>
Vector2<T>::Vector2(T x, T y)
{
	this->vector[0] = x;
	this->vector[1] = y;
}

template <typename T>
Vector2<T>::Vector2(T vector[2])
{
	this->vector[0] = vector[0];
	this->vector[1] = vector[1];
}

template <typename T>
void Vector2<T>::show()
{
	std::cout << "Vector2(" << this->vector[0] << ", " << this->vector[1] << ")" << std::endl << std::endl;
}

template <typename T>
Vector2<T> Vector2<T>::operator +(Vector2 other)
{
	return Vector2<T>(
		this->vector[0] + other[0],
		this->vector[1] + other[1]
		);
}

template <typename T>
Vector2<T> Vector2<T>::operator -(Vector2 other)
{
	return Vector2<T>(
		this->vector[0] - other[0],
		this->vector[1] - other[1]
		);
}

template <typename T>
Vector2<T> Vector2<T>::operator *(Vector2 other)
{
	return Vector2<T>(
		this->vector[0] * other[0],
		this->vector[1] * other[1]
		);
}

template <typename T>
Vector2<T> Vector2<T>::operator *(Matrix2<T> other)
{
	T vec[2];

	for (int i = 0; i < 2; i++)
		vec[i] = this->vector[0] * other[i] +
		this->vector[1] * other[i + 2];

	return Vector2<T>(vec);
}

template <typename T>
T Vector2<T>::dot(Vector2<T> a, Vector2<T> b)
{
	Vector2<T> p = a * b;

	T res = {};

	for (int i = 0; i < 2; i++)
		res += p[i];

	return res;
}

template <typename T>
T& Vector2<T>::operator[] (const int index)
{
	return this->vector[index];
}

template <typename T>
T Vector2<T>::length()
{
	T res = {};
	for (int i = 0; i < 2; i++)
		res += vector[i] * vector[i];
	return sqrt(res);
}

template <typename T>
void Vector2<T>::normalize()
{
	T len = length();
	for (int i = 0; i < 2; i++)
		vector[i] /= len;
}

template class Vector2<float>;
template class Vector2<int>;
template class Vector2<double>;

#pragma endregion