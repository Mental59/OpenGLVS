#pragma once
#include "Vector.h"
#include "defines.h"

class Matrix4
{
public:
	GEOMfloat elements[16];

	Matrix4(GEOMfloat matrix[16]);

	Matrix4(GEOMfloat a11, GEOMfloat a12, GEOMfloat a13, GEOMfloat a14,
		GEOMfloat a21, GEOMfloat a22, GEOMfloat a23, GEOMfloat a24,
		GEOMfloat a31, GEOMfloat a32, GEOMfloat a33, GEOMfloat a34,
		GEOMfloat a41, GEOMfloat a42, GEOMfloat a43, GEOMfloat a44);

	Matrix4 operator +(Matrix4 other);

	Matrix4 operator -(Matrix4 other);

	Matrix4 operator *(Matrix4 other);

	Vector4 operator *(Vector4 other);

	GEOMfloat& operator[] (const int index);

	void show();

	friend Matrix4 operator *(Matrix4 mat, GEOMfloat right);

	friend Matrix4 operator *(GEOMfloat left, Matrix4 mat);

	friend Matrix4 operator /(Matrix4 mat, GEOMfloat right);

};

class Matrix3
{
public:
	GEOMfloat elements[9];

	Matrix3(GEOMfloat matrix[9]);

	Matrix3(GEOMfloat a11, GEOMfloat a12, GEOMfloat a13, 
		GEOMfloat a21, GEOMfloat a22, GEOMfloat a23, 
		GEOMfloat a31, GEOMfloat a32, GEOMfloat a33);

	Matrix3 operator +(Matrix3 other);

	Matrix3 operator -(Matrix3 other);

	Matrix3 operator *(Matrix3 other);

	Vector3 operator *(Vector3 other);

	GEOMfloat& operator[] (const int index);

	void show();

	friend Matrix3 operator *(Matrix3 mat, GEOMfloat right);

	friend Matrix3 operator *(GEOMfloat left, Matrix3 mat);

	friend Matrix3 operator /(Matrix3 mat, GEOMfloat right);

};

class Matrix2
{
public:
	GEOMfloat elements[4];

	Matrix2(GEOMfloat matrix[4]);

	Matrix2(GEOMfloat a11, GEOMfloat a12, GEOMfloat a21, GEOMfloat a22);

	Matrix2 operator +(Matrix2 other);

	Matrix2 operator -(Matrix2 other);

	Matrix2 operator *(Matrix2 other);

	Vector2 operator *(Vector2 other);

	GEOMfloat& operator[] (const int index);

	void show();

	friend Matrix2 operator *(Matrix2 mat, GEOMfloat right);

	friend Matrix2 operator *(GEOMfloat left, Matrix2 mat);

	friend Matrix2 operator /(Matrix2 mat, GEOMfloat right);

};

Matrix4 createTranslateMatrix(GEOMfloat x, GEOMfloat y, GEOMfloat z);

Matrix4 createScaleMatrix(GEOMfloat sx, GEOMfloat sy, GEOMfloat sz);

Matrix4 createRotateXMatrix(GEOMfloat angle);
Matrix4 createRotateYMatrix(GEOMfloat angle);
Matrix4 createRotateZMatrix(GEOMfloat angle);

Matrix4 createPerspectiveProjectionMatrix(GEOMfloat far, GEOMfloat near, GEOMfloat fov, int screen_width, int screen_height);

Matrix4 createParallelProjectionMatrix(GEOMfloat far, GEOMfloat near, GEOMfloat fov, int screen_width, int screen_height);

Matrix3 getMainMinor(Matrix4 mat4);
Matrix2 getMainMinor(Matrix3 mat3);

Matrix4 createLookAtMatrix(Vector3 cameraPos, Vector3 targetPos, Vector3 up);