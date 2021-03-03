#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <math.h>

#define PI 3.14159265359f

#pragma region Class Matrix4

Matrix4::Matrix4(GEOMfloat matrix[16])
{
	for (int i = 0; i < 16; i++)
		this->elements[i] = matrix[i];
}

Matrix4::Matrix4(GEOMfloat a11, GEOMfloat a12, GEOMfloat a13, GEOMfloat a14,
	GEOMfloat a21, GEOMfloat a22, GEOMfloat a23, GEOMfloat a24,
	GEOMfloat a31, GEOMfloat a32, GEOMfloat a33, GEOMfloat a34,
	GEOMfloat a41, GEOMfloat a42, GEOMfloat a43, GEOMfloat a44)
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
	GEOMfloat result[16];

	for (int i = 0; i < 16; i++)
		result[i] = this->elements[i] + other[i];

	return Matrix4(result);
}

Matrix4 Matrix4::operator -(Matrix4 other)
{
	GEOMfloat result[16];

	for (int i = 0; i < 16; i++)
		result[i] = this->elements[i] - other[i];

	return Matrix4(result);
}

Matrix4 Matrix4::operator *(Matrix4 other)
{
	GEOMfloat result[16];

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
	GEOMfloat vec[4];

	for (int i = 0; i < 4; i++)
		vec[i] = other[0] * this->elements[i] +
		other[1] * this->elements[i + 4] +
		other[2] * this->elements[i + 8] +
		other[3] * this->elements[i + 12];

	return Vector4(vec);
}

GEOMfloat& Matrix4::operator[] (const int index)
{
	return this->elements[index];
}

Matrix4 operator *(Matrix4 mat, GEOMfloat right)
{
	GEOMfloat result[16];

	for (int i = 0; i < 16; i++)
		result[i] = mat[i] * right;

	return Matrix4(result);
}

Matrix4 operator *(GEOMfloat left, Matrix4 mat)
{
	GEOMfloat result[16];

	for (int i = 0; i < 16; i++)
		result[i] = mat[i] * left;

	return Matrix4(result);
}

Matrix4 operator /(Matrix4 mat, GEOMfloat right)
{
	GEOMfloat result[16];

	for (int i = 0; i < 16; i++)
		result[i] = mat[i] / right;

	return Matrix4(result);
}

#pragma endregion



#pragma region Class Matrix3

Matrix3::Matrix3(GEOMfloat matrix[9])
{
	for (int i = 0; i < 9; i++)
		this->elements[i] = matrix[i];
}

Matrix3::Matrix3(GEOMfloat a11, GEOMfloat a12, GEOMfloat a13,
	GEOMfloat a21, GEOMfloat a22, GEOMfloat a23,
	GEOMfloat a31, GEOMfloat a32, GEOMfloat a33)
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
	GEOMfloat result[9];

	for (int i = 0; i < 9; i++)
		result[i] = this->elements[i] + other[i];

	return Matrix3(result);
}

Matrix3 Matrix3::operator -(Matrix3 other)
{
	GEOMfloat result[9];

	for (int i = 0; i < 9; i++)
		result[i] = this->elements[i] - other[i];

	return Matrix3(result);
}

Matrix3 Matrix3::operator *(Matrix3 other)
{
	GEOMfloat result[9];

	for (int i = 0; i < 9; i += 3)
		for (int j = 0; j < 3; j++)
			result[i + j] = this->elements[i] * other[j] +
			this->elements[i + 1] * other[j + 3] +
			this->elements[i + 2] * other[j + 6];

	return Matrix3(result);
}

Vector3 Matrix3::operator *(Vector3 other)
{
	GEOMfloat vec[3];

	for (int i = 0; i < 3; i++)
		vec[i] = other[0] * this->elements[i] +
		other[1] * this->elements[i + 3] +
		other[2] * this->elements[i + 6];

	return Vector3(vec);
}

GEOMfloat& Matrix3::operator[] (const int index)
{
	return this->elements[index];
}

Matrix3 operator *(Matrix3 mat, GEOMfloat right)
{
	GEOMfloat result[9];

	for (int i = 0; i < 9; i++)
		result[i] = mat[i] * right;

	return Matrix3(result);
}

Matrix3 operator *(GEOMfloat left, Matrix3 mat)
{
	GEOMfloat result[9];

	for (int i = 0; i < 9; i++)
		result[i] = mat[i] * left;

	return Matrix3(result);
}

Matrix3 operator /(Matrix3 mat, GEOMfloat right)
{
	GEOMfloat result[9];

	for (int i = 0; i < 9; i++)
		result[i] = mat[i] / right;

	return Matrix3(result);
}

#pragma endregion



#pragma region class Matrix2

Matrix2::Matrix2(GEOMfloat matrix[4])
{
	for (int i = 0; i < 4; i++)
		this->elements[i] = matrix[i];
}

Matrix2::Matrix2(GEOMfloat a11, GEOMfloat a12, GEOMfloat a21, GEOMfloat a22)
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
	GEOMfloat result[4];

	for (int i = 0; i < 4; i++)
		result[i] = this->elements[i] + other[i];

	return Matrix2(result);
}

Matrix2 Matrix2::operator -(Matrix2 other)
{
	GEOMfloat result[4];

	for (int i = 0; i < 4; i++)
		result[i] = this->elements[i] - other[i];

	return Matrix2(result);
}

Matrix2 Matrix2::operator *(Matrix2 other)
{
	GEOMfloat result[4];

	for (int i = 0; i < 4; i += 2)
		for (int j = 0; j < 2; j++)
			result[i + j] = this->elements[i] * other[j] +
			this->elements[i + 1] * other[j + 2];

	return Matrix2(result);
}

Vector2 Matrix2::operator *(Vector2 other)
{
	GEOMfloat vec[2];

	for (int i = 0; i < 2; i++)
		vec[i] = other[0] * this->elements[i] +
		other[1] * this->elements[i + 2];

	return Vector2(vec);
}

GEOMfloat& Matrix2::operator[] (const int index)
{
	return this->elements[index];
}

Matrix2 operator *(Matrix2 mat, GEOMfloat right)
{
	GEOMfloat result[4];

	for (int i = 0; i < 4; i++)
		result[i] = mat[i] * right;

	return Matrix2(result);
}

Matrix2 operator *(GEOMfloat left, Matrix2 mat)
{
	GEOMfloat result[4];

	for (int i = 0; i < 4; i++)
		result[i] = mat[i] * left;

	return Matrix2(result);
}

Matrix2 operator /(Matrix2 mat, GEOMfloat right)
{
	GEOMfloat result[4];

	for (int i = 0; i < 4; i++)
		result[i] = mat[i] / right;

	return Matrix2(result);
}

#pragma endregion



#pragma region Affine transformation matrices

Matrix4 createTranslateMatrix(GEOMfloat x, GEOMfloat y, GEOMfloat z)
{
	GEOMfloat mat[16] = {
		1.0f, 0.0f, 0.0f, x,
		0.0f, 1.0f, 0.0f, y,
		0.0f, 0.0f, 1.0f, z,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	return Matrix4(mat);
}

Matrix4 createScaleMatrix(GEOMfloat sx, GEOMfloat sy, GEOMfloat sz)
{
	GEOMfloat mat[16] = {
		sx, 0.0f, 0.0f, 0.0f,
		0.0f, sy, 0.0f, 0.0f,
		0.0f, 0.0f, sz, 0.0f,
		0.0f, 0.0f, 0.0f,  1.0f,
	};

	return Matrix4(mat);
}

Matrix4 createRotateXMatrix(GEOMfloat angle)
{
	GEOMfloat c = cos(angle * PI / 180.0f);
	GEOMfloat s = sin(angle * PI / 180.0f);

	GEOMfloat mat[16] = {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, c, -s, 0.0f,
		0.0f, s, c, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	return Matrix4(mat);
}

Matrix4 createRotateYMatrix(GEOMfloat angle)
{
	GEOMfloat c = cos(angle * PI / 180.0f);
	GEOMfloat s = sin(angle * PI / 180.0f);

	GEOMfloat mat[16] = {
		c, 0.0f, s, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		-s, 0.0f, c, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	return Matrix4(mat);
}

Matrix4 createRotateZMatrix(GEOMfloat angle)
{
	GEOMfloat c = cos(angle * PI / 180.0f);
	GEOMfloat s = sin(angle * PI / 180.0f);

	GEOMfloat mat[16] = {
		c, -s, 0.0f, 0.0f,
		s, c, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	return Matrix4(mat);
}

Matrix4 createPerspectiveProjectionMatrix(GEOMfloat far, GEOMfloat near, GEOMfloat fov, int screen_width, int screen_height)
{
	GEOMfloat right, left, bottom, top;

	GEOMfloat scale = tan((fov / 2.0f) * (PI / 180.0f)) * near;

	right = scale;
	left = -right;
	top = ((GEOMfloat)screen_width / (GEOMfloat)screen_height) * scale;
	bottom = -top;

	GEOMfloat mat[16] = {
		(2.0f * near) / (right - left), 0.0f, 0.0f, 0.0f,
		0.0f, (2.0f * near) / (top - bottom), 0.0f, 0.0f,
		0.0f, 0.0f, -(far + near) / (far - near), -(2.0f * far * near) / (far - near),
		0.0f, 0.0f, -1.0f, 0.0f
	};

	return Matrix4(mat);
}

Matrix4 createParallelProjectionMatrix(GEOMfloat far, GEOMfloat near, GEOMfloat fov, int screen_width, int screen_height)
{
	GEOMfloat right, left, bottom, top;

	GEOMfloat scale = tan((fov / 2.0f) * (PI / 180.0f)) * near;

	right = scale;
	left = -right;
	top = ((GEOMfloat)screen_width / (GEOMfloat)screen_height) * scale;
	bottom = -top;

	GEOMfloat mat[16] = {
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
	GEOMfloat mat[9] = {
		mat4.elements[0], mat4.elements[1], mat4.elements[2],
		mat4.elements[4], mat4.elements[5], mat4.elements[6],
		mat4.elements[8], mat4.elements[9], mat4.elements[10]
	};
	return Matrix3(mat);
}

Matrix2 getMainMinor(Matrix3 mat3)
{
	GEOMfloat mat[4] = {
		mat3.elements[0], mat3.elements[1],
		mat3.elements[3], mat3.elements[4]
	};
	return Matrix2(mat);
}