#define _USE_MATH_DEFINES

#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include <chrono>
#include <math.h>

using namespace std;

class Timer
{
private:
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, ratio<1> >;

	chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now()) {}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

int main()
{
	Vector2<float> f_vec2a = Vector2<float>(1.2f, 3.3f);
	Vector2<float> f_vec2b = Vector2<float>(0.6f, 1.5f);

	Vector3<float> f_vec3a = Vector3<float>(1.2f, 3.3f, 4.5f);
	Vector3<float> f_vec3b = Vector3<float>(0.6f, 1.5f, 7.6f);

	Vector4<float> f_vec4a = Vector4<float>(1.2f, 3.3f, 4.5f, 6.6f);
	Vector4<float> f_vec4b = Vector4<float>(0.6f, 1.5f, 7.6f, 6.5f);

	Matrix2<float> f_mat2a = Matrix2<float>(
		1.2f, 3.3f, 
		7.8f, 2.2f);
	Matrix2<float> f_mat2b = Matrix2<float>(
		0.6f, 1.5f, 
		5.5f, 1.2f);

	Matrix3<float> f_mat3a = Matrix3<float>(
		1.2f, 3.3f, 4.5f, 
		0.6f, 1.5f, 7.6f, 
		0.6f, 1.5f, 7.6f);
	Matrix3<float> f_mat3b = Matrix3<float>(
		0.6f, 1.5f, 7.6f, 
		4.5f, 0.6f, 1.5f, 
		4.5f, 0.6f, 1.5f);

	Matrix4<float> f_mat4a = Matrix4<float>(
		1.2f, 3.3f, 4.5f, 6.6f, 
		3.3f, 4.5f, 0.6f, 1.5f, 
		3.3f, 4.5f, 0.6f, 1.5f, 
		3.3f, 4.5f, 0.6f, 1.5f);
	Matrix4<float> f_mat4b = Matrix4<float>(
		0.6f, 1.5f, 7.6f, 6.5f, 
		1.5f, 4.5f, 0.6f, 1.5f, 
		1.5f, 4.5f, 0.6f, 1.5f, 
		1.5f, 4.5f, 0.6f, 1.5f);

	/*(f_vec2a * f_vec2b).show();
	(f_vec3a * f_vec3b).show();
	(f_vec4a * f_vec4b).show();

	cout << "-----------------------------------------------------------" << endl << endl;

	(f_vec2a + f_vec2b).show();
	(f_vec3a + f_vec3b).show();
	(f_vec4a + f_vec4b).show();

	cout << "-----------------------------------------------------------" << endl << endl;

	(f_vec2a - f_vec2b).show();
	(f_vec3a - f_vec3b).show();
	(f_vec4a - f_vec4b).show();

	cout << "-----------------------------------------------------------" << endl << endl;

	(f_mat2a * f_mat2b).show();
	(f_mat3a * f_mat3b).show();
	(f_mat4a * f_mat4b).show();

	cout << "-----------------------------------------------------------" << endl << endl;

	(f_mat2a + f_mat2b).show();
	(f_mat3a + f_mat3b).show();
	(f_mat4a + f_mat4b).show();

	cout << "-----------------------------------------------------------" << endl << endl;

	(f_mat2a - f_mat2b).show();
	(f_mat3a - f_mat3b).show();
	(f_mat4a - f_mat4b).show();

	cout << "-----------------------------------------------------------" << endl << endl;

	(f_vec2a * f_mat2a).show();
	(f_vec3a * f_mat3a).show();
	(f_vec4a * f_mat4a).show();

	cout << "-----------------------------------------------------------" << endl << endl;*/

	/*cout << f_vec2a.length() << endl;
	f_vec2a.normalize();
	cout << f_vec2a.length() << endl;
	f_vec2a.show();

	cout << f_vec4a.length() << endl;
	f_vec4a.normalize();
	cout << f_vec4a.length() << endl;
	f_vec4a.show();*/

	cout << Vector4<float>::dot(f_vec4a, f_vec4b) << endl;
	cout << Vector3<float>::dot(f_vec3a, f_vec3b) << endl;
	cout << Vector2<float>::dot(f_vec2a, f_vec2b) << endl;

	return 0;
}