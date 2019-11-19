#include <iostream>
#include<iomanip>
using namespace std;
class Matrix
{
private:
	int m; // row
	int n; // col
	double **valueMT;//elements of matrix
public:
	Matrix();
	~Matrix();//delete matrix
	Matrix(const Matrix & a);
	void Input();//enter matrix
	void OutPut();//print matrix
	int Multiply(const Matrix & a);//return 1 if if possible multiply else return 0
	double determinant();// return -99 if can not calculate determinant else return determinant
	void Cofactor(double**&temp, int p, int q, int n);
	double** adjoint();
	void Inverse(double deter);

	int Rank();
	void Gauss(double *&b);
	void System_of_Linear_Equations(int r);
}; 
