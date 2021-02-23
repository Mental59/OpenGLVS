#include "Matrix.h"
#include <iostream>
#include <math.h>

#pragma region Class Matrix4

template <typename T>
Matrix4<T>::Matrix4(T matrix[16])
{
	for (int i = 0; i < 16; i++)
		this->matrix[i] = matrix[i];
}

template <typename T>
Matrix4<T>::Matrix4(T a11, T a12, T a13, T a14, T a21, T a22, T a23, T a24, T a31, T a32, T a33, T a34, T a41, T a42, T a43, T a44)
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

template <typename T>
void Matrix4<T>::show()
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

template <typename T>
Matrix4<T> Matrix4<T>::operator +(Matrix4 other)
{
	T result[16];

	for (int i = 0; i < 16; i++)
		result[i] = this->matrix[i] + other[i];

	return Matrix4(result);
}

template <typename T>
Matrix4<T> Matrix4<T>::operator -(Matrix4 other)
{
	T result[16];

	for (int i = 0; i < 16; i++)
		result[i] = this->matrix[i] - other[i];

	return Matrix4(result);
}

template <typename T>
Matrix4<T> Matrix4<T>::operator *(Matrix4 other)
{
	T result[16];

	for (int i = 0; i < 16; i += 4)
		for (int j = 0; j < 4; j++)
			result[i + j] = this->matrix[i] * other[j] +
							this->matrix[i + 1] * other[j + 4] +
							this->matrix[i + 2] * other[j + 8] +
							this->matrix[i + 3] * other[j + 12];

	return Matrix4(result);
}

template <typename T>
T& Matrix4<T>::operator[] (const int index)
{
	return this->matrix[index];
}

template class Matrix4<int>;
template class Matrix4<float>;
template class Matrix4<double>;

#pragma endregion



#pragma region Class Matrix3

template <typename T>
Matrix3<T>::Matrix3(T matrix[9])
{
	for (int i = 0; i < 9; i++)
		this->matrix[i] = matrix[i];
}

template <typename T>
Matrix3<T>::Matrix3(T a11, T a12, T a13, T a21, T a22, T a23, T a31, T a32, T a33)
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

template <typename T>
void Matrix3<T>::show()
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

template <typename T>
Matrix3<T> Matrix3<T>::operator +(Matrix3 other)
{
	T result[9];

	for (int i = 0; i < 9; i++)
		result[i] = this->matrix[i] + other[i];

	return Matrix3(result);
}

template <typename T>
Matrix3<T> Matrix3<T>::operator -(Matrix3 other)
{
	T result[9];

	for (int i = 0; i < 9; i++)
		result[i] = this->matrix[i] - other[i];

	return Matrix3(result);
}

template <typename T>
Matrix3<T> Matrix3<T>::operator *(Matrix3 other)
{
	T result[9];

	for (int i = 0; i < 9; i += 3)
		for (int j = 0; j < 3; j++)
			result[i + j] = this->matrix[i] * other[j] +
			this->matrix[i + 1] * other[j + 3] +
			this->matrix[i + 2] * other[j + 6];

	return Matrix3(result);
}

template <typename T>
T& Matrix3<T>::operator[] (const int index)
{
	return this->matrix[index];
}

template class Matrix3<int>;
template class Matrix3<float>;
template class Matrix3<double>;

#pragma endregion



#pragma region class Matrix2

template <typename T>
Matrix2<T>::Matrix2(T matrix[4])
{
	for (int i = 0; i < 4; i++)
		this->matrix[i] = matrix[i];
}

template <typename T>
Matrix2<T>::Matrix2(T a11, T a12, T a21, T a22)
{
	this->matrix[0] = a11;
	this->matrix[1] = a12;
	this->matrix[2] = a21;
	this->matrix[3] = a22;
}

template <typename T>
void Matrix2<T>::show()
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

template <typename T>
Matrix2<T> Matrix2<T>::operator +(Matrix2 other)
{
	T result[4];

	for (int i = 0; i < 4; i++)
		result[i] = this->matrix[i] + other[i];

	return Matrix2(result);
}

template <typename T>
Matrix2<T> Matrix2<T>::operator -(Matrix2 other)
{
	T result[4];

	for (int i = 0; i < 4; i++)
		result[i] = this->matrix[i] - other[i];

	return Matrix2(result);
}

template <typename T>
Matrix2<T> Matrix2<T>::operator *(Matrix2 other)
{
	T result[4];

	for (int i = 0; i < 4; i += 2)
		for (int j = 0; j < 2; j++)
			result[i + j] = this->matrix[i] * other[j] +
			this->matrix[i + 1] * other[j + 2];

	return Matrix2(result);
}

template <typename T>
T& Matrix2<T>::operator[] (const int index)
{
	return this->matrix[index];
}

template class Matrix2<int>;
template class Matrix2<float>;
template class Matrix2<double>;

#pragma endregion



#pragma region Матрицы аффинного преобразования

template <typename T>
Matrix4<T> createTranslateMatrix(T x, T y, T z)
{
	T mat[16] = {
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1
	};

	return Matrix4<T>(mat);
}

template Matrix4<float> createTranslateMatrix<float>(float x, float y, float z);
template Matrix4<double> createTranslateMatrix<double>(double x, double y, double z);
template Matrix4<int> createTranslateMatrix<int>(int x, int y, int z);

template <typename T> 
Matrix4<T> createScaleMatrix(T sx, T sy, T sz)
{
	T mat[16] = {
		sx, 0, 0, 0,
		0, sy, 0, 0,
		0, 0, sz, 0,
		0, 0, 0,  1,
	};

	return Matrix4<T>(mat);
}

template Matrix4<float> createScaleMatrix<float>(float sx, float sy, float sz);
template Matrix4<double> createScaleMatrix<double>(double sx, double sy, double sz);
template Matrix4<int> createScaleMatrix<int>(int sx, int sy, int sz);

template <typename T> 
Matrix4<T> createRotateMatrix(T x, T y, T z, float angle_rad)
{
	T c = cos(angle_rad);
	T s = sin(angle_rad);

	T mat[16] = {
		x * x * (1 - c) + c, x * y * (1 - c) - z * s, x * z * (1 - c) + y * s, 0,
		y * x * (1 - c) + z * s, y * y * (1 - c) + c, y * z * (1 - c) - x * s, 0,
		x * z * (1 - c) - y * s, y * z * (1 - c) + x * s, z * z * (1 - c) + c, 0,
		0, 0, 0, 1
	};

	return Matrix4<T>(mat);
}

template Matrix4<float> createRotateMatrix<float>(float x, float y, float z, float angle_rad);
template Matrix4<double> createRotateMatrix<double>(double x, double y, double z, float angle_rad);
template Matrix4<int> createRotateMatrix<int>(int x, int y, int z, float angle_rad);

template <typename T> 
Matrix4<T> createPerspectiveProjectionMatrix(T far, T near, T angle_rad, int screen_width, int screen_height)
{
	T right, left, bottom, top;

	T tang = tan(angle_rad / 2);

	T temp1 = near * tang;
	left = -temp1, right = temp1;

	T temp2 = near * (screen_width / screen_height) * tang;
	bottom = -temp2, top = temp2;

	T mat[16] = {
		(2 * near) / (right - left), 0, (right + left) / (right - left), 0,
		0, (2 * near) / (top - bottom), (top + bottom) / (top - bottom), 0,
		0, 0, -(far + near) / (far - near), -(2 * far * near) / (far - near),
		0, 0, -1, 0
	};

	return Matrix4<T>(mat);
}

template Matrix4<float> createPerspectiveProjectionMatrix<float>(float far, float near, float angle_rad, int screen_width, int screen_height);
template Matrix4<double> createPerspectiveProjectionMatrix<double>(double far, double near, double angle_rad, int screen_width, int screen_height);
template Matrix4<int> createPerspectiveProjectionMatrix<int>(int far, int near, int angle_rad, int screen_width, int screen_height);

template <typename T> 
Matrix4<T> createParallelProjectionMatrix(T far, T near, T angle_rad, int screen_width, int screen_height)
{
	T right, left, bottom, top;

	T tang = tan(angle_rad / 2);

	T temp1 = near * tang;
	left = -temp1, right = temp1;

	T temp2 = near * (screen_width / screen_height) * tang;
	bottom = -temp2, top = temp2;

	T mat[16] = {
		2 / (right - left), 0, 0, -(right + left) / (right - left),
		0, 2 / (top - bottom), 0, -(top + bottom) / (top - bottom),
		0, 0, -2 / (far - near), -(far + near) / (far - near),
		0, 0, 0, 1
	};

	return Matrix4<T>(mat);
}

template Matrix4<float> createParallelProjectionMatrix<float>(float far, float near, float angle_rad, int screen_width, int screen_height);
template Matrix4<double> createParallelProjectionMatrix<double>(double far, double near, double angle_rad, int screen_width, int screen_height);
template Matrix4<int> createParallelProjectionMatrix<int>(int far, int near, int angle_rad, int screen_width, int screen_height);

#pragma endregion