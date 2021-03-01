#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <math.h>

#define PI 3.14159265359f

#pragma region Class Matrix4

Matrix4::Matrix4(float matrix[16])
{
	for (int i = 0; i < 16; i++)
		this->elements[i] = matrix[i];
}

Matrix4::Matrix4(float a11, float a12, float a13, float a14,
	float a21, float a22, float a23, float a24,
	float a31, float a32, float a33, float a34,
	float a41, float a42, float a43, float a44)
{
	this->elements[0] = a11;
	this->elements[1] = a12;
	this->elements[2] = a13;
	this->elements[3] = a14;
	this->elements[4] = a21;
	this->elements[5] = a22;
	this->elements[6] = a23;
	this->elements[7] = a24;
	this->elements[8] = a31;
	this->elements[9] = a32;
	this->elements[10] = a33;
	this->elements[11] = a34;
	this->elements[12] = a41;
	this->elements[13] = a42;
	this->elements[14] = a43;
	this->elements[15] = a44;
}

void Matrix4::show()
{
	int k = 0;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "(" << this->elements[k++];
		std::cout << "\t" << this->elements[k++];
		std::cout << "\t" << this->elements[k++];
		std::cout << "\t" << this->elements[k++];
		std::cout << ")" << std::endl;
	}
	std::cout << std::endl;
}

Matrix4 Matrix4::operator +(Matrix4 other)
{
	float result[16];

	for (int i = 0; i < 16; i++)
		result[i] = this->elements[i] + other[i];

	return Matrix4(result);
}

Matrix4 Matrix4::operator -(Matrix4 other)
{
	float result[16];

	for (int i = 0; i < 16; i++)
		result[i] = this->elements[i] - other[i];

	return Matrix4(result);
}

Matrix4 Matrix4::operator *(Matrix4 other)
{
	float result[16];

	for (int i = 0; i < 16; i += 4)
		for (int j = 0; j < 4; j++)
			result[i + j] = this->elements[i] * other[j] +
			this->elements[i + 1] * other[j + 4] +
			this->elements[i + 2] * other[j + 8] +
			this->elements[i + 3] * other[j + 12];

	return Matrix4(result);
}

Vector4 Matrix4::operator *(Vector4 other)
{
	float vec[4];

	for (int i = 0; i < 4; i++)
		vec[i] = other[0] * this->elements[i] +
		other[1] * this->elements[i + 4] +
		other[2] * this->elements[i + 8] +
		other[3] * this->elements[i + 12];

	return Vector4(vec);
}

float& Matrix4::operator[] (const int index)
{
	return this->elements[index];
}

Matrix4 operator *(Matrix4 mat, float right)
{
	float result[16];

	for (int i = 0; i < 16; i++)
		result[i] = mat[i] * right;

	return Matrix4(result);
}

Matrix4 operator *(float left, Matrix4 mat)
{
	float result[16];

	for (int i = 0; i < 16; i++)
		result[i] = mat[i] * left;

	return Matrix4(result);
}

Matrix4 operator /(Matrix4 mat, float right)
{
	float result[16];

	for (int i = 0; i < 16; i++)
		result[i] = mat[i] / right;

	return Matrix4(result);
}

#pragma endregion



#pragma region Class Matrix3

Matrix3::Matrix3(float matrix[9])
{
	for (int i = 0; i < 9; i++)
		this->elements[i] = matrix[i];
}

Matrix3::Matrix3(float a11, float a12, float a13,
	float a21, float a22, float a23,
	float a31, float a32, float a33)
{
	this->elements[0] = a11;
	this->elements[1] = a12;
	this->elements[2] = a13;
	this->elements[3] = a21;
	this->elements[4] = a22;
	this->elements[5] = a23;
	this->elements[6] = a31;
	this->elements[7] = a32;
	this->elements[8] = a33;
}

void Matrix3::show()
{
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "(" << this->elements[k++];
		std::cout << "\t" << this->elements[k++];
		std::cout << "\t" << this->elements[k++];
		std::cout << ")" << std::endl;
	}
	std::cout << std::endl;
}

Matrix3 Matrix3::operator +(Matrix3 other)
{
	float result[9];

	for (int i = 0; i < 9; i++)
		result[i] = this->elements[i] + other[i];

	return Matrix3(result);
}

Matrix3 Matrix3::operator -(Matrix3 other)
{
	float result[9];

	for (int i = 0; i < 9; i++)
		result[i] = this->elements[i] - other[i];

	return Matrix3(result);
}

Matrix3 Matrix3::operator *(Matrix3 other)
{
	float result[9];

	for (int i = 0; i < 9; i += 3)
		for (int j = 0; j < 3; j++)
			result[i + j] = this->elements[i] * other[j] +
			this->elements[i + 1] * other[j + 3] +
			this->elements[i + 2] * other[j + 6];

	return Matrix3(result);
}

Vector3 Matrix3::operator *(Vector3 other)
{
	float vec[3];

	for (int i = 0; i < 3; i++)
		vec[i] = other[0] * this->elements[i] +
		other[1] * this->elements[i + 3] +
		other[2] * this->elements[i + 6];

	return Vector3(vec);
}

float& Matrix3::operator[] (const int index)
{
	return this->elements[index];
}

Matrix3 operator *(Matrix3 mat, float right)
{
	float result[9];

	for (int i = 0; i < 9; i++)
		result[i] = mat[i] * right;

	return Matrix3(result);
}

Matrix3 operator *(float left, Matrix3 mat)
{
	float result[9];

	for (int i = 0; i < 9; i++)
		result[i] = mat[i] * left;

	return Matrix3(result);
}

Matrix3 operator /(Matrix3 mat, float right)
{
	float result[9];

	for (int i = 0; i < 9; i++)
		result[i] = mat[i] / right;

	return Matrix3(result);
}

#pragma endregion



#pragma region class Matrix2

Matrix2::Matrix2(float matrix[4])
{
	for (int i = 0; i < 4; i++)
		this->elements[i] = matrix[i];
}

Matrix2::Matrix2(float a11, float a12, float a21, float a22)
{
	this->elements[0] = a11;
	this->elements[1] = a12;
	this->elements[2] = a21;
	this->elements[3] = a22;
}

void Matrix2::show()
{
	int k = 0;
	for (int i = 0; i < 2; i++)
	{
		std::cout << "(" << this->elements[k++];
		std::cout << "\t" << this->elements[k++];
		std::cout << ")" << std::endl;
	}
	std::cout << std::endl;
}

Matrix2 Matrix2::operator +(Matrix2 other)
{
	float result[4];

	for (int i = 0; i < 4; i++)
		result[i] = this->elements[i] + other[i];

	return Matrix2(result);
}

Matrix2 Matrix2::operator -(Matrix2 other)
{
	float result[4];

	for (int i = 0; i < 4; i++)
		result[i] = this->elements[i] - other[i];

	return Matrix2(result);
}

Matrix2 Matrix2::operator *(Matrix2 other)
{
	float result[4];

	for (int i = 0; i < 4; i += 2)
		for (int j = 0; j < 2; j++)
			result[i + j] = this->elements[i] * other[j] +
			this->elements[i + 1] * other[j + 2];

	return Matrix2(result);
}

Vector2 Matrix2::operator *(Vector2 other)
{
	float vec[2];

	for (int i = 0; i < 2; i++)
		vec[i] = other[0] * this->elements[i] +
		other[1] * this->elements[i + 2];

	return Vector2(vec);
}

float& Matrix2::operator[] (const int index)
{
	return this->elements[index];
}

Matrix2 operator *(Matrix2 mat, float right)
{
	float result[4];

	for (int i = 0; i < 4; i++)
		result[i] = mat[i] * right;

	return Matrix2(result);
}

Matrix2 operator *(float left, Matrix2 mat)
{
	float result[4];

	for (int i = 0; i < 4; i++)
		result[i] = mat[i] * left;

	return Matrix2(result);
}

Matrix2 operator /(Matrix2 mat, float right) 
{
	float result[4];

	for (int i = 0; i < 4; i++)
		result[i] = mat[i] / right;

	return Matrix2(result);
}

#pragma endregion



#pragma region Affine transformation matrices

Matrix4 createTranslateMatrix(float x, float y, float z)
{
	float mat[16] = {
		1.0f, 0.0f, 0.0f, x,
		0.0f, 1.0f, 0.0f, y,
		0.0f, 0.0f, 1.0f, z,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	return Matrix4(mat);
}

Matrix4 createScaleMatrix(float sx, float sy, float sz)
{
	float mat[16] = {
		sx, 0.0f, 0.0f, 0.0f,
		0.0f, sy, 0.0f, 0.0f,
		0.0f, 0.0f, sz, 0.0f,
		0.0f, 0.0f, 0.0f,  1.0f,
	};

	return Matrix4(mat);
}

Matrix4 createRotateXMatrix(float angle)
{
	float c = cos(angle * PI / 180.0f);
	float s = sin(angle * PI / 180.0f);

	float mat[16] = {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, c, -s, 0.0f,
		0.0f, s, c, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	return Matrix4(mat);
}

Matrix4 createRotateYMatrix(float angle)
{
	float c = cos(angle * PI / 180.0f);
	float s = sin(angle * PI / 180.0f);

	float mat[16] = {
		c, 0.0f, s, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		-s, 0.0f, c, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	return Matrix4(mat);
}

Matrix4 createRotateZMatrix(float angle)
{
	float c = cos(angle * PI / 180.0f);
	float s = sin(angle * PI / 180.0f);

	float mat[16] = {
		c, -s, 0.0f, 0.0f,
		s, c, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	return Matrix4(mat);
}

Matrix4 createPerspectiveProjectionMatrix(float far, float near, float fov, int screen_width, int screen_height)
{
	float right, left, bottom, top;

	float scale = tan((fov / 2.0f) * (PI / 180.0f)) * near;

	right = scale;
	left = -right;
	top = ((float)screen_width / (float)screen_height) * scale;
	bottom = -top;

	float mat[16] = {
		(2.0f * near) / (right - left), 0.0f, 0.0f, 0.0f,
		0.0f, (2.0f * near) / (top - bottom), 0.0f, 0.0f,
		0.0f, 0.0f, -(far + near) / (far - near), -(2.0f * far * near) / (far - near),
		0.0f, 0.0f, -1.0f, 0.0f
	};

	return Matrix4(mat);
}

Matrix4 createParallelProjectionMatrix(float far, float near, float fov, int screen_width, int screen_height)
{
	float right, left, bottom, top;

	float scale = tan((fov / 2.0f) * (PI / 180.0f)) * near;

	right = scale;
	left = -right;
	top = ((float)screen_width / (float)screen_height) * scale;
	bottom = -top;

	float mat[16] = {
		2.0f / (right - left), 0.0f, 0.0f, 0.0f,
		0.0f, 2.0f / (top - bottom), 0.0f, 0.0f,
		0.0f, 0.0f, -2.0f / (far - near), -(far + near) / (far - near),
		0.0f, 0.0f, 0.0f, 1.0f
	};

	return Matrix4(mat);
}

#pragma endregion

Matrix3 getMainMinor(Matrix4 mat4)
{
	float mat[9] = {
		mat4.elements[0], mat4.elements[1], mat4.elements[2],
		mat4.elements[4], mat4.elements[5], mat4.elements[6],
		mat4.elements[8], mat4.elements[9], mat4.elements[10]
	};
	return Matrix3(mat);
}

Matrix2 getMainMinor(Matrix3 mat3)
{
	float mat[4] = {
		mat3.elements[0], mat3.elements[1],
		mat3.elements[3], mat3.elements[4]
	};
	return Matrix2(mat);
}