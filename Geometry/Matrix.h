#pragma once

template <typename T> class Matrix4
{
private:
	T matrix[16];

public:
	Matrix4(T matrix[16]);

	Matrix4(T a11, T a12, T a13, T a14, T a21, T a22, T a23, T a24, T a31, T a32, T a33, T a34, T a41, T a42, T a43, T a44);

	Matrix4<T> operator +(Matrix4<T> other);

	Matrix4<T> operator -(Matrix4<T> other);

	Matrix4<T> operator *(Matrix4<T> other);

	T& operator[] (const int index);

	void show();

	friend Matrix4<T> operator *(Matrix4<T> mat, T right)
	{
		T result[16];

		for (int i = 0; i < 16; i++)
			result[i] = mat[i] * right;

		return Matrix4<T>(result);
	}

	friend Matrix4<T> operator *(T left, Matrix4<T> mat)
	{
		T result[16];

		for (int i = 0; i < 16; i++)
			result[i] = mat[i] * left;

		return Matrix4<T>(result);
	}

	friend Matrix4<T> operator /(Matrix4<T> mat, T right)
	{
		T result[16];

		for (int i = 0; i < 16; i++)
			result[i] = mat[i] / right;

		return Matrix4<T>(result);
	}

};

template <typename T> class Matrix3
{
private:
	T matrix[9];

public:
	Matrix3(T matrix[9]);

	Matrix3(T a11, T a12, T a13, T a21, T a22, T a23, T a31, T a32, T a33);

	Matrix3<T> operator +(Matrix3<T> other);

	Matrix3<T> operator -(Matrix3<T> other);

	Matrix3<T> operator *(Matrix3<T> other);

	T& operator[] (const int index);

	void show();

	friend Matrix3<T> operator *(Matrix3<T> mat, T right)
	{
		T result[9];

		for (int i = 0; i < 9; i++)
			result[i] = mat[i] * right;

		return Matrix3<T>(result);
	}

	friend Matrix3<T> operator *(T left, Matrix3<T> mat)
	{
		T result[9];

		for (int i = 0; i < 9; i++)
			result[i] = mat[i] * left;

		return Matrix3<T>(result);
	}

	friend Matrix3<T> operator /(Matrix3<T> mat, T right)
	{
		T result[9];

		for (int i = 0; i < 9; i++)
			result[i] = mat[i] / right;

		return Matrix3<T>(result);
	}

};

template <typename T> class Matrix2
{
private:
	T matrix[4];

public:
	Matrix2(T matrix[4]);

	Matrix2(T a11, T a12, T a21, T a22);

	Matrix2<T> operator +(Matrix2<T> other);

	Matrix2<T> operator -(Matrix2<T> other);

	Matrix2<T> operator *(Matrix2<T> other);

	T& operator[] (const int index);

	void show();

	friend Matrix2<T> operator *(Matrix2<T> mat, T right)
	{
		T result[4];

		for (int i = 0; i < 4; i++)
			result[i] = mat[i] * right;

		return Matrix2<T>(result);
	}

	friend Matrix2<T> operator *(T left, Matrix2<T> mat)
	{
		T result[4];

		for (int i = 0; i < 4; i++)
			result[i] = mat[i] * left;

		return Matrix2<T>(result);
	}

	friend Matrix2<T> operator /(Matrix2<T> mat, T right)
	{
		T result[4];

		for (int i = 0; i < 4; i++)
			result[i] = mat[i] / right;

		return Matrix2<T>(result);
	}

};

template <typename T> Matrix4<T> createTranslateMatrix(T x, T y, T z);

template <typename T> Matrix4<T> createScaleMatrix(T sx, T sy, T sz);

template <typename T> Matrix4<T> createRotateMatrix(T x, T y, T z, float angle_rad);

template <typename T> Matrix4<T> createPerspectiveProjectionMatrix(T far, T near, T angle_rad, int screen_width, int screen_height);

template <typename T> Matrix4<T> createParallelProjectionMatrix(T far, T near, T angle_rad, int screen_width, int screen_height);
