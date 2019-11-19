#include "vector.h"
using namespace std;

Vector::Vector()
{
	valueVT= NULL;
}

Vector::Vector(int N, double x)
{
	valueVT = new double[N];
	for (int i = 0; i < n; i++)
		valueVT[i] = x;
}

Vector::Vector(const Vector & a)
{
	n = a.n;
	valueVT = new double[n];
	for (int i = 0; i < n; i++)
		valueVT[i] = a.valueVT[i];
}

Vector::~Vector()
{
	if (valueVT != NULL)
		delete[] valueVT;
}

void Vector::input()
{
	cout << "Enter vector" << endl;
	cout << "How many elements are there in vector: ";
	cin >> n;
	valueVT = new double[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Vector[" << i << "]=";
		cin >> valueVT[i];
	}
}

void Vector::output()
{
	for (int i = 0; i < n; i++)
		cout << valueVT[i] * 1000 / 1000 << "  ";
	cout << endl;
}

int Vector::add(const Vector & a)
{
	if (n != a.n) return 0;
	for (int i = 0; i < n; i++)
		valueVT[i] += a.valueVT[i];
	return 1;
}

void Vector::multiplyK(const double & k)
{
	for (int i = 0; i < n; i++)
		valueVT[i] *= k;
}
