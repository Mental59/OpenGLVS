#include "pch.h"
#include "Vector.h"
#include "Matrix.h"
#include <iostream>

#pragma region Class Vector4

Vector4::Vector4(GEOMfloat x, GEOMfloat y, GEOMfloat z, GEOMfloat w)
{
	this->elements[0] = x;
	this->elements[1] = y;
	this->elements[2] = z;
	this->elements[3] = w;
}

Vector4::Vector4(GEOMfloat vector[4])
{
	this->elements[0] = vector[0];
	this->elements[1] = vector[1];
	this->elements[2] = vector[2];
	this->elements[3] = vector[3];
}

void Vector4::show()
{
	std::cout << "Vector4(" << this->elements[0] << ", " << this->elements[1] << ", " << this->elements[2] << ", " << this->elements[3] << ")" << std::endl << std::endl;
}

Vector4 Vector4::operator +(Vector4 other)
{
	return Vector4(
		this->elements[0] + other[0],
		this->elements[1] + other[1],
		this->elements[2] + other[2],
		this->elements[3] + other[3]
		);
}

Vector4 Vector4::operator -(Vector4 other)
{
	return Vector4(
		this->elements[0] - other[0],
		this->elements[1] - other[1],
		this->elements[2] - other[2],
		this->elements[3] - other[3]
		);
}

Vector4 Vector4::operator *(Vector4 other)
{
	return Vector4(
		this->elements[0] * other[0],
		this->elements[1] * other[1],
		this->elements[2] * other[2],
		this->elements[3] * other[3]
		);
}

GEOMfloat Vector4::dot(Vector4 a, Vector4 b)
{
	Vector4 p = a * b;

	GEOMfloat res = 0.0f;

	for (int i = 0; i < 4; i++)
		res += p[i];

	return res;
}

GEOMfloat& Vector4::operator[] (const int index)
{
	return this->elements[index];
}

GEOMfloat Vector4::length()
{
	GEOMfloat res = 0.0f;
	for (int i = 0; i < 4; i++)
		res += elements[i] * elements[i];
	return sqrt(res);
}

void Vector4::normalize()
{
	GEOMfloat len = length();
	for (int i = 0; i < 4; i++)
		elements[i] /= len;
}

Vector4 operator *(Vector4 vec, GEOMfloat right)
{
	return Vector4(
		vec[0] * right,
		vec[1] * right,
		vec[2] * right,
		vec[3] * right
	);
}

Vector4 operator *(GEOMfloat left, Vector4 vec)
{
	return Vector4(
		vec[0] * left,
		vec[1] * left,
		vec[2] * left,
		vec[3] * left
	);
}

Vector4 operator /(Vector4 vec, GEOMfloat right)
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

Vector3::Vector3(GEOMfloat x, GEOMfloat y, GEOMfloat z)
{
	this->elements[0] = x;
	this->elements[1] = y;
	this->elements[2] = z;
}

Vector3::Vector3(GEOMfloat vector[3])
{
	this->elements[0] = vector[0];
	this->elements[1] = vector[1];
	this->elements[2] = vector[2];
}

void Vector3::show()
{
	std::cout << "Vector3(" << this->elements[0] << ", " << this->elements[1] << ", " << this->elements[2] << ")" << std::endl << std::endl;
}

Vector3 Vector3::operator +(Vector3 other)
{
	return Vector3(
		this->elements[0] + other[0],
		this->elements[1] + other[1],
		this->elements[2] + other[2]
		);
}

Vector3 Vector3::operator -(Vector3 other)
{
	return Vector3(
		this->elements[0] - other[0],
		this->elements[1] - other[1],
		this->elements[2] - other[2]
		);
}

Vector3 Vector3::operator *(Vector3 other)
{
	return Vector3(
		this->elements[0] * other[0],
		this->elements[1] * other[1],
		this->elements[2] * other[2]
		);
}

GEOMfloat Vector3::dot(Vector3 a, Vector3 b)
{
	Vector3 p = a * b;

	GEOMfloat res = 0.0f;

	for (int i = 0; i < 3; i++)
		res += p[i];

	return res;
}

GEOMfloat& Vector3::operator[] (const int index)
{
	return this->elements[index];
}

GEOMfloat Vector3::length()
{
	GEOMfloat res = 0.0f;
	for (int i = 0; i < 3; i++)
		res += elements[i] * elements[i];
	return sqrt(res);
}

void Vector3::normalize()
{
	GEOMfloat len = length();
	for (int i = 0; i < 3; i++)
		elements[i] /= len;
}

Vector3 operator *(Vector3 vec, GEOMfloat right)
{
	return Vector3(
		vec[0] * right,
		vec[1] * right,
		vec[2] * right
	);
}

Vector3 operator *(GEOMfloat left, Vector3 vec)
{
	return Vector3(
		vec[0] * left,
		vec[1] * left,
		vec[2] * left
	);
}

Vector3 operator /(Vector3 vec, GEOMfloat right)
{
	return Vector3(
		vec[0] / right,
		vec[1] / right,
		vec[2] / right
	);
}

#pragma endregion



#pragma region Class Vector2

Vector2::Vector2(GEOMfloat x, GEOMfloat y)
{
	this->elements[0] = x;
	this->elements[1] = y;
}

Vector2::Vector2(GEOMfloat vector[2])
{
	this->elements[0] = vector[0];
	this->elements[1] = vector[1];
}

void Vector2::show()
{
	std::cout << "Vector2(" << this->elements[0] << ", " << this->elements[1] << ")" << std::endl << std::endl;
}

Vector2 Vector2::operator +(Vector2 other)
{
	return Vector2(
		this->elements[0] + other[0],
		this->elements[1] + other[1]
		);
}

Vector2 Vector2::operator -(Vector2 other)
{
	return Vector2(
		this->elements[0] - other[0],
		this->elements[1] - other[1]
		);
}

Vector2 Vector2::operator *(Vector2 other)
{
	return Vector2(
		this->elements[0] * other[0],
		this->elements[1] * other[1]
		);
}

GEOMfloat Vector2::dot(Vector2 a, Vector2 b)
{
	Vector2 p = a * b;

	GEOMfloat res = 0.0f;

	for (int i = 0; i < 2; i++)
		res += p[i];

	return res;
}

GEOMfloat& Vector2::operator[] (const int index)
{
	return this->elements[index];
}

GEOMfloat Vector2::length()
{
	GEOMfloat res = 0.0f;
	for (int i = 0; i < 2; i++)
		res += elements[i] * elements[i];
	return sqrt(res);
}

void Vector2::normalize()
{
	GEOMfloat len = length();
	for (int i = 0; i < 2; i++)
		elements[i] /= len;
}

Vector2 operator *(Vector2 vec, GEOMfloat right)
{
	return Vector2(
		vec[0] * right,
		vec[1] * right
	);
}

Vector2 operator *(GEOMfloat left, Vector2 vec)
{
	return Vector2(
		vec[0] * left,
		vec[1] * left
	);
}

Vector2 operator /(Vector2 vec, GEOMfloat right)
{
	return Vector2(
		vec[0] / right,
		vec[1] / right
	);
}

#pragma endregion
