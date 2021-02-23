#include "pch.h"
#include "Vector.h"
#include "Matrix.h"
#include <iostream>

#pragma region Class Vector4

Vector4::Vector4(float x, float y, float z, float w)
{
	this->vector[0] = x;
	this->vector[1] = y;
	this->vector[2] = z;
	this->vector[3] = w;
}

Vector4::Vector4(float vector[4])
{
	this->vector[0] = vector[0];
	this->vector[1] = vector[1];
	this->vector[2] = vector[2];
	this->vector[3] = vector[3];
}

void Vector4::show()
{
	std::cout << "Vector4(" << this->vector[0] << ", " << this->vector[1] << ", " << this->vector[2] << ", " << this->vector[3] << ")" << std::endl << std::endl;
}

Vector4 Vector4::operator +(Vector4 other)
{
	return Vector4(
		this->vector[0] + other[0],
		this->vector[1] + other[1],
		this->vector[2] + other[2],
		this->vector[3] + other[3]
		);
}

Vector4 Vector4::operator -(Vector4 other)
{
	return Vector4(
		this->vector[0] - other[0],
		this->vector[1] - other[1],
		this->vector[2] - other[2],
		this->vector[3] - other[3]
		);
}

Vector4 Vector4::operator *(Vector4 other)
{
	return Vector4(
		this->vector[0] * other[0],
		this->vector[1] * other[1],
		this->vector[2] * other[2],
		this->vector[3] * other[3]
		);
}

Vector4 Vector4::operator *(Matrix4 other)
{
	float vec[4];

	for (int i = 0; i < 4; i++)
		vec[i] = this->vector[0] * other[i] +
		this->vector[1] * other[i + 4] +
		this->vector[2] * other[i + 8] +
		this->vector[3] * other[i + 12];

	return Vector4(vec);
}

float Vector4::dot(Vector4 a, Vector4 b)
{
	Vector4 p = a * b;

	float res = 0.0f;

	for (int i = 0; i < 4; i++)
		res += p[i];

	return res;
}

float& Vector4::operator[] (const int index)
{
	return this->vector[index];
}

float Vector4::length()
{
	float res = 0.0f;
	for (int i = 0; i < 4; i++)
		res += vector[i] * vector[i];
	return sqrt(res);
}

void Vector4::normalize()
{
	float len = length();
	for (int i = 0; i < 4; i++)
		vector[i] /= len;
}

Vector4 operator *(Vector4 vec, float right)
{
	return Vector4(
		vec[0] * right,
		vec[1] * right,
		vec[2] * right,
		vec[3] * right
	);
}

Vector4 operator *(float left, Vector4 vec)
{
	return Vector4(
		vec[0] * left,
		vec[1] * left,
		vec[2] * left,
		vec[3] * left
	);
}

Vector4 operator /(Vector4 vec, float right)
{
	return Vector4(
		vec[0] / right,
		vec[1] / right,
		vec[2] / right,
		vec[3] / right
	);
}

#pragma endregion



#pragma region Class Vector3

Vector3::Vector3(float x, float y, float z)
{
	this->vector[0] = x;
	this->vector[1] = y;
	this->vector[2] = z;
}

Vector3::Vector3(float vector[3])
{
	this->vector[0] = vector[0];
	this->vector[1] = vector[1];
	this->vector[2] = vector[2];
}

void Vector3::show()
{
	std::cout << "Vector3(" << this->vector[0] << ", " << this->vector[1] << ", " << this->vector[2] << ")" << std::endl << std::endl;
}

Vector3 Vector3::operator +(Vector3 other)
{
	return Vector3(
		this->vector[0] + other[0],
		this->vector[1] + other[1],
		this->vector[2] + other[2]
		);
}

Vector3 Vector3::operator -(Vector3 other)
{
	return Vector3(
		this->vector[0] - other[0],
		this->vector[1] - other[1],
		this->vector[2] - other[2]
		);
}

Vector3 Vector3::operator *(Vector3 other)
{
	return Vector3(
		this->vector[0] * other[0],
		this->vector[1] * other[1],
		this->vector[2] * other[2]
		);
}

Vector3 Vector3::operator *(Matrix3 other)
{
	float vec[3];

	for (int i = 0; i < 3; i++)
		vec[i] = this->vector[0] * other[i] +
		this->vector[1] * other[i + 3] +
		this->vector[2] * other[i + 6];

	return Vector3(vec);
}

float Vector3::dot(Vector3 a, Vector3 b)
{
	Vector3 p = a * b;

	float res = 0.0f;

	for (int i = 0; i < 3; i++)
		res += p[i];

	return res;
}

float& Vector3::operator[] (const int index)
{
	return this->vector[index];
}

float Vector3::length()
{
	float res = 0.0f;
	for (int i = 0; i < 3; i++)
		res += vector[i] * vector[i];
	return sqrt(res);
}

void Vector3::normalize()
{
	float len = length();
	for (int i = 0; i < 3; i++)
		vector[i] /= len;
}

Vector3 operator *(Vector3 vec, float right)
{
	return Vector3(
		vec[0] * right,
		vec[1] * right,
		vec[2] * right
	);
}

Vector3 operator *(float left, Vector3 vec)
{
	return Vector3(
		vec[0] * left,
		vec[1] * left,
		vec[2] * left
	);
}

Vector3 operator /(Vector3 vec, float right)
{
	return Vector3(
		vec[0] / right,
		vec[1] / right,
		vec[2] / right
	);
}

#pragma endregion



#pragma region Class Vector2

Vector2::Vector2(float x, float y)
{
	this->vector[0] = x;
	this->vector[1] = y;
}

Vector2::Vector2(float vector[2])
{
	this->vector[0] = vector[0];
	this->vector[1] = vector[1];
}

void Vector2::show()
{
	std::cout << "Vector2(" << this->vector[0] << ", " << this->vector[1] << ")" << std::endl << std::endl;
}

Vector2 Vector2::operator +(Vector2 other)
{
	return Vector2(
		this->vector[0] + other[0],
		this->vector[1] + other[1]
		);
}

Vector2 Vector2::operator -(Vector2 other)
{
	return Vector2(
		this->vector[0] - other[0],
		this->vector[1] - other[1]
		);
}

Vector2 Vector2::operator *(Vector2 other)
{
	return Vector2(
		this->vector[0] * other[0],
		this->vector[1] * other[1]
		);
}

Vector2 Vector2::operator *(Matrix2 other)
{
	float vec[2];

	for (int i = 0; i < 2; i++)
		vec[i] = this->vector[0] * other[i] +
		this->vector[1] * other[i + 2];

	return Vector2(vec);
}

float Vector2::dot(Vector2 a, Vector2 b)
{
	Vector2 p = a * b;

	float res = 0.0f;

	for (int i = 0; i < 2; i++)
		res += p[i];

	return res;
}

float& Vector2::operator[] (const int index)
{
	return this->vector[index];
}

float Vector2::length()
{
	float res = 0.0f;
	for (int i = 0; i < 2; i++)
		res += vector[i] * vector[i];
	return sqrt(res);
}

void Vector2::normalize()
{
	float len = length();
	for (int i = 0; i < 2; i++)
		vector[i] /= len;
}

Vector2 operator *(Vector2 vec, float right)
{
	return Vector2(
		vec[0] * right,
		vec[1] * right
	);
}

Vector2 operator *(float left, Vector2 vec)
{
	return Vector2(
		vec[0] * left,
		vec[1] * left
	);
}

Vector2 operator /(Vector2 vec, float right)
{
	return Vector2(
		vec[0] / right,
		vec[1] / right
	);
}

#pragma endregion
