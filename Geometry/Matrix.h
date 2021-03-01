#pragma once
#include "Vector.h"

class Matrix4
{
public:
	float elements[16];

	Matrix4(float matrix[16]);

	Matrix4(float a11, float a12, float a13, float a14, 
		float a21, float a22, float a23, float a24, 
		float a31, float a32, float a33, float a34, 
		float a41, float a42, float a43, float a44);

	Matrix4 operator +(Matrix4 other);

	Matrix4 operator -(Matrix4 other);

	Matrix4 operator *(Matrix4 other);

	Vector4 operator *(Vector4 other);

	float& operator[] (const int index);

	void show();

	friend Matrix4 operator *(Matrix4 mat, float right);

	friend Matrix4 operator *(float left, Matrix4 mat);

	friend Matrix4 operator /(Matrix4 mat, float right);

};

class Matrix3
{
public:
	float elements[9];

	Matrix3(float matrix[9]);

	Matrix3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33);

	Matrix3 operator +(Matrix3 other);

	Matrix3 operator -(Matrix3 other);

	Matrix3 operator *(Matrix3 other);

	Vector3 operator *(Vector3 other);

	float& operator[] (const int index);

	void show();

	friend Matrix3 operator *(Matrix3 mat, float right);

	friend Matrix3 operator *(float left, Matrix3 mat);

	friend Matrix3 operator /(Matrix3 mat, float right);

};

class Matrix2
{
public:
	float elements[4];

	Matrix2(float matrix[4]);

	Matrix2(float a11, float a12, float a21, float a22);

	Matrix2 operator +(Matrix2 other);

	Matrix2 operator -(Matrix2 other);

	Matrix2 operator *(Matrix2 other);

	Vector2 operator *(Vector2 other);

	float& operator[] (const int index);

	void show();

	friend Matrix2 operator *(Matrix2 mat, float right);

	friend Matrix2 operator *(float left, Matrix2 mat);

	friend Matrix2 operator /(Matrix2 mat, float right);

};

Matrix4 createTranslateMatrix(float x, float y, float z);

Matrix4 createScaleMatrix(float sx, float sy, float sz);

Matrix4 createRotateXMatrix(float angle);
Matrix4 createRotateYMatrix(float angle);
Matrix4 createRotateZMatrix(float angle);

Matrix4 createPerspectiveProjectionMatrix(float far, float near, float fov, int screen_width, int screen_height);

Matrix4 createParallelProjectionMatrix(float far, float near, float fov, int screen_width, int screen_height);

Matrix3 getMainMinor(Matrix4 mat4);
Matrix2 getMainMinor(Matrix3 mat3);