#pragma once

class Vector4
{
	
public:
	float vector[4];

	Vector4(float x, float y, float z, float w);

	Vector4(float vector[4]);

	Vector4 operator +(Vector4 other);

	Vector4 operator -(Vector4 other);

	Vector4 operator *(Vector4 other);

	static float dot(Vector4 a, Vector4 b);

	float& operator[] (const int index);

	void show();

	void normalize();

	float length();

	friend Vector4 operator *(Vector4 vec, float right);

	friend Vector4 operator *(float left, Vector4 vec);

	friend Vector4 operator /(Vector4 vec, float right);

};

class Vector3
{

public:
	float vector[3];

	Vector3(float x, float y, float z);

	Vector3(float vector[3]);

	Vector3 operator +(Vector3 other);

	Vector3 operator -(Vector3 other);

	Vector3 operator *(Vector3 other);

	static float dot(Vector3 a, Vector3 b);

	float& operator[] (const int index);

	void show();

	void normalize();

	float length();

	friend Vector3 operator *(Vector3 vec, float right);

	friend Vector3 operator *(float left, Vector3 vec);

	friend Vector3 operator /(Vector3 vec, float right);

};

class Vector2
{

public:
	float vector[2];

	Vector2(float x, float y);

	Vector2(float vector[2]);

	Vector2 operator +(Vector2 other);

	Vector2 operator -(Vector2 other);

	Vector2 operator *(Vector2 other);

	static float dot(Vector2 a, Vector2 b);

	float& operator[] (const int index);

	void show();

	void normalize();

	float length();

	friend Vector2 operator *(Vector2 vec, float right);

	friend Vector2 operator *(float left, Vector2 vec);

	friend Vector2 operator /(Vector2 vec, float right);

};
