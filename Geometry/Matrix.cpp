#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <math.h>

#define PI 3.14159265359f

#pragma region Class Matrix4

Matrix4::Matrix4(float matrix[16])
{
	for (int i = 0; i < 16; i++)
		this->matrix[i] = matrix[i];
}

Matrix4::Matrix4(float a11, float a12, float a13, float a14,
	float a21, float a22, float a23, float a24,
	float a31, float a32, float a33, float a34,
	float a41, float a42, float a43, float a44)
{
	this->matrix[0] = a11;
	this->matrix[1] = a12;
	this->matrix[2] = a13;
	this->matrix[3] = a14;
	this->matrix[4] = a21;
	this->matrix[5] = a22;
	this->matrix[6] = a23;
	this->matrix[7] = a24;
	this->matrix[8] = a31;
	this->matrix[9] = a32;
	this->matrix[10] = a33;
	this->matrix[11] = a34;
	this->matrix[12] = a41;
	this->matrix[13] = a42;
	this->matrix[14] = a43;
	this->matrix[15] = a44;
}

void Matrix4::show()
{
	int k = 0;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "(" << this->matrix[k++];
		std::cout << "\t" << this->matrix[k++];
		std::cout << "\t" << this->matrix[k++];
		std::cout << "\t" << this->matrix[k++];
		std::cout << ")" << std::endl;
	}
	std::cout << std::endl;
}

Matrix4 Matrix4::operator +(Matrix4 other)
{
	float result[16];

	for (int i = 0; i < 16; i++)
		result[i] = this->matrix[i] + other[i];

	return Matrix4(result);
}

Matrix4 Matrix4::operator -(Matrix4 other)
{
	float result[16];

	for (int i = 0; i < 16; i++)
		result[i] = this->matrix[i] - other[i];

	return Matrix4(result);
}

Matrix4 Matrix4::operator *(Matrix4 other)
{
	float result[16];

	for (int i = 0; i < 16; i += 4)
		for (int j = 0; j < 4; j++)
			result[i + j] = this->matrix[i] * other[j] +
			this->matrix[i + 1] * other[j + 4] +
			this->matrix[i + 2] * other[j + 8] +
			this->matrix[i + 3] * other[j + 12];

	return Matrix4(result);
}

float& Matrix4::operator[] (const int index)
{
	return this->matrix[index];
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
		this->matrix[i] = matrix[i];
}

Matrix3::Matrix3(float a11, float a12, float a13,
	float a21, float a22, float a23,
	float a31, float a32, float a33)
{
	this->matrix[0] = a11;
	this->matrix[1] = a12;
	this->matrix[2] = a13;
	this->matrix[3] = a21;
	this->matrix[4] = a22;
	this->matrix[5] = a23;
	this->matrix[6] = a31;
	this->matrix[7] = a32;
	this->matrix[8] = a33;
}

void Matrix3::show()
{
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "(" << this->matrix[k++];
		std::cout << "\t" << this->matrix[k++];
		std::cout << "\t" << this->matrix[k++];
		std::cout << ")" << std::endl;
	}
	std::cout << std::endl;
}

Matrix3 Matrix3::operator +(Matrix3 other)
{
	float result[9];

	for (int i = 0; i < 9; i++)
		result[i] = this->matrix[i] + other[i];

	return Matrix3(result);
}

Matrix3 Matrix3::operator -(Matrix3 other)
{
	float result[9];

	for (int i = 0; i < 9; i++)
		result[i] = this->matrix[i] - other[i];

	return Matrix3(result);
}

Matrix3 Matrix3::operator *(Matrix3 other)
{
	float result[9];

	for (int i = 0; i < 9; i += 3)
		for (int j = 0; j < 3; j++)
			result[i + j] = this->matrix[i] * other[j] +
			this->matrix[i + 1] * other[j + 3] +
			this->matrix[i + 2] * other[j + 6];

	return Matrix3(result);
}

float& Matrix3::operator[] (const int index)
{
	return this->matrix[index];
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
		this->matrix[i] = matrix[i];
}

Matrix2::Matrix2(float a11, float a12, float a21, float a22)
{
	this->matrix[0] = a11;
	this->matrix[1] = a12;
	this->matrix[2] = a21;
	this->matrix[3] = a22;
}

void Matrix2::show()
{
	int k = 0;
	for (int i = 0; i < 2; i++)
	{
		std::cout << "(" << this->matrix[k++];
		std::cout << "\t" << this->matrix[k++];
		std::cout << ")" << std::endl;
	}
	std::cout << std::endl;
}

Matrix2 Matrix2::operator +(Matrix2 other)
{
	float result[4];

	for (int i = 0; i < 4; i++)
		result[i] = this->matrix[i] + other[i];

	return Matrix2(result);
}

Matrix2 Matrix2::operator -(Matrix2 other)
{
	float result[4];

	for (int i = 0; i < 4; i++)
		result[i] = this->matrix[i] - other[i];

	return Matrix2(result);
}

Matrix2 Matrix2::operator *(Matrix2 other)
{
	float result[4];

	for (int i = 0; i < 4; i += 2)
		for (int j = 0; j < 2; j++)
			result[i + j] = this->matrix[i] * other[j] +
			this->matrix[i + 1] * other[j + 2];

	return Matrix2(result);
}

float& Matrix2::operator[] (const int index)
{
	return this->matrix[index];
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

Matrix4 createRotateMatrix(float x, float y, float z, float angle)
{
	float c = cos(angle * PI / 180.0f);
	float s = sin(angle * PI / 180.0f);

	float mat[16] = {
		x * x * (1.0f - c) + c, x * y * (1.0f - c) - z * s, x * z * (1.0f - c) + y * s, 0.0f,
		y * x * (1.0f - c) + z * s, y * y * (1.0f - c) + c, y * z * (1 - c) - x * s, 0.0f,
		x * z * (1.0f - c) - y * s, y * z * (1.0f - c) + x * s, z * z * (1 - c) + c, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	return Matrix4(mat);
}

Matrix4 createPerspectiveProjectionMatrix(float far, float near, float angle, int screen_width, int screen_height)
{
	float right, left, bottom, top;

	float tang = tan((angle * PI / 180.0f) / 2.0f);

	float temp1 = near * tang;
	left = -temp1, right = temp1;

	float temp2 = near * ((float)screen_width / (float)screen_height) * tang;
	bottom = -temp2, top = temp2;

	float mat[16] = {
		(2.0f * near) / (right - left), 0.0f, (right + left) / (right - left), 0.0f,
		0.0f, (2.0f * near) / (top - bottom), (top + bottom) / (top - bottom), 0.0f,
		0.0f, 0.0f, -(far + near) / (far - near), -(2.0f * far * near) / (far - near),
		0.0f, 0.0f, -1.0f, 0.0f
	};

	return Matrix4(mat);
}

Matrix4 createParallelProjectionMatrix(float far, float near, float angle, int screen_width, int screen_height)
{
	float right, left, bottom, top;

	float tang = tan((angle * PI / 180.0f) / 2.0f);

	float temp1 = near * tang;
	left = -temp1, right = temp1;

	float temp2 = near * ((float)screen_width / (float)screen_height) * tang;
	bottom = -temp2, top = temp2;

	float mat[16] = {
		2.0f / (right - left), 0.0f, 0.0f, -(right + left) / (right - left),
		0.0f, 2.0f / (top - bottom), 0.0f, -(top + bottom) / (top - bottom),
		0.0f, 0.0f, -2.0f / (far - near), -(far + near) / (far - near),
		0.0f, 0.0f, 0.0f, 1.0f
	};

	return Matrix4(mat);
}

#pragma endregion