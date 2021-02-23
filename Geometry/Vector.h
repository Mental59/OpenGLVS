#pragma once
#include "Matrix.h"

template <typename T> class Vector4
{
private:
	T vector[4];

public:
	Vector4(T x, T y, T z, T w);

	Vector4(T vector[4]);

	Vector4<T> operator +(Vector4<T> other);

	Vector4<T> operator -(Vector4<T> other);

	Vector4<T> operator *(Vector4<T> other);

	Vector4<T> operator *(Matrix4<T> other);

	static T dot(Vector4<T> a, Vector4<T> b);

	T& operator[] (const int index);

	void show();

	void normalize();

	T length();

	friend Vector4<T> operator *(Vector4<T> vec, T right)
	{
		return Vector4<T>(
			vec[0] * right,
			vec[1] * right,
			vec[2] * right,
			vec[3] * right
			);
	}

	friend Vector4<T> operator *(T left, Vector4<T> vec)
	{
		return Vector4<T>(
			vec[0] * left,
			vec[1] * left,
			vec[2] * left,
			vec[3] * left
			);
	}

	friend Vector4<T> operator /(Vector4<T> vec, T right)
	{
		return Vector4<T>(
			vec[0] / right,
			vec[1] / right,
			vec[2] / right,
			vec[3] / right
			);
	}

};

template <typename T> class Vector3
{
private:
	T vector[3];

public:
	Vector3(T x, T y, T z);

	Vector3(T vector[3]);

	Vector3<T> operator +(Vector3<T> other);

	Vector3<T> operator -(Vector3<T> other);

	Vector3<T> operator *(Vector3<T> other);

	Vector3<T> operator *(Matrix3<T> other);

	static T dot(Vector3<T> a, Vector3<T> b);

	T& operator[] (const int index);

	void show();

	void normalize();

	T length();

	friend Vector3<T> operator *(Vector3<T> vec, T right)
	{
		return Vector3<T>(
			vec[0] * right,
			vec[1] * right,
			vec[2] * right
			);
	}

	friend Vector3<T> operator *(T left, Vector3<T> vec)
	{
		return Vector3<T>(
			vec[0] * left,
			vec[1] * left,
			vec[2] * left
		);
	}

	friend Vector3<T> operator /(Vector3<T> vec, T right)
	{
		return Vector3<T>(
			vec[0] / right,
			vec[1] / right,
			vec[2] / right
		);
	}

};

template <typename T> class Vector2
{
private:
	T vector[2];

public:
	Vector2(T x, T y);

	Vector2(T vector[2]);

	Vector2<T> operator +(Vector2<T> other);

	Vector2<T> operator -(Vector2<T> other);

	Vector2<T> operator *(Vector2<T> other);

	Vector2<T> operator *(Matrix2<T> other);

	static T dot(Vector2<T> a, Vector2<T> b);

	T& operator[] (const int index);

	void show();

	void normalize();

	T length();

	friend Vector2<T> operator *(Vector2<T> vec, T right)
	{
		return Vector2<T>(
			vec[0] * right,
			vec[1] * right
			);
	}

	friend Vector2<T> operator *(T left, Vector2<T> vec)
	{
		return Vector2<T>(
			vec[0] * left,
			vec[1] * left
			);
	}

	friend Vector2<T> operator /(Vector2<T> vec, T right)
	{
		return Vector2<T>(
			vec[0] / right,
			vec[1] / right
			);
	}

};