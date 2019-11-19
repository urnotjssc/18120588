#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Vector
{
private:
	double *valueVT;//element of vector
	int n;//n is the length of vector
public:

	Vector();
	Vector(int N, double x); // create a vector with N elements, each element's valua is x
	Vector(const Vector &a); // 
	~Vector();
	void input();// enter vector
	void output();//print vector
	int add(const Vector &a); // return 1 if if possible add
	void multiplyK(const double &k);// multiply vector by K
};
