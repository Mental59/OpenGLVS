#pragma once
#include "defines.h"

class Vector4
{
	
public:
	GEOMfloat elements[4];

	Vector4(GEOMfloat x, GEOMfloat y, GEOMfloat z, GEOMfloat w);

	Vector4(GEOMfloat vector[4]);

	Vector4 operator +(Vector4 other);

	Vector4 operator -(Vector4 other);

	Vector4 operator *(Vector4 other);

	static GEOMfloat dot(Vector4 a, Vector4 b);

	GEOMfloat& operator[] (const int index);

	void show();

	void normalize();

	GEOMfloat length();

	friend Vector4 operator *(Vector4 vec, GEOMfloat right);

	friend Vector4 operator *(GEOMfloat left, Vector4 vec);

	friend Vector4 operator /(Vector4 vec, GEOMfloat right);

};

class Vector3
{

public:
	GEOMfloat elements[3];

	Vector3(GEOMfloat x, GEOMfloat y, GEOMfloat z);

	Vector3(GEOMfloat vector[3]);

	Vector3 operator +(Vector3 other);

	Vector3 operator -(Vector3 other);

	Vector3 operator *(Vector3 other);

	static GEOMfloat dot(Vector3 a, Vector3 b);

	GEOMfloat& operator[] (const int index);

	void show();

	void normalize();

	GEOMfloat length();

	friend Vector3 operator *(Vector3 vec, GEOMfloat right);

	friend Vector3 operator *(GEOMfloat left, Vector3 vec);

	friend Vector3 operator /(Vector3 vec, GEOMfloat right);

};

class Vector2
{

public:
	GEOMfloat elements[2];

	Vector2(GEOMfloat x, GEOMfloat y);

	Vector2(GEOMfloat vector[2]);

	Vector2 operator +(Vector2 other);

	Vector2 operator -(Vector2 other);

	Vector2 operator *(Vector2 other);

	static GEOMfloat dot(Vector2 a, Vector2 b);

	GEOMfloat& operator[] (const int index);

	void show();

	void normalize();

	GEOMfloat length();

	friend Vector2 operator *(Vector2 vec, GEOMfloat right);

	friend Vector2 operator *(GEOMfloat left, Vector2 vec);

	friend Vector2 operator /(Vector2 vec, GEOMfloat right);

};
