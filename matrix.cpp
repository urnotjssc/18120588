#include "matrix.h"
using namespace std;


Matrix::Matrix()
{
	m = 0;
	n = 0;
	valueMT = NULL;
}
Matrix::~Matrix()
{
	if (valueMT == NULL)
		return;
	for (int i = 0; i < m; i++)
	{
		delete[] valueMT[i];
		valueMT[i] = NULL;
	}
	delete[] valueMT;
	valueMT = NULL;
}
Matrix::Matrix(const Matrix & a)
{
	m = a.m;
	n = a.n;
	valueMT = new double *[m]; // create m rows
	for (int i = 0; i < m; i++)
		valueMT[i] = new double[n]; // create n cols
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			valueMT[i][j] = a.valueMT[i][j];
}

void Matrix::Input()//Enter matrix
{
	cout << "Enter matrix " << endl;
	cout << "Number of rows: ";
	cin >> m;
	cout << "Number of columns: ";
	cin >> n;
	valueMT = new double *[m]; // create m rows
	for (int i = 0; i < m; i++)
		valueMT[i] = new double[n]; // create n cols
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "Matrix[" << i << "][" << j << "]=";
			cin >> valueMT[i][j];
		}
}
void Matrix::OutPut()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << valueMT[i][j]*1000/1000 << " ";
		cout << endl;
	}
}//Print matrix

int Matrix::Multiply(const Matrix & a)
{
	if (n != a.m)
		return 0;

	double ** temp = new double *[m]; // create a temporary matrix to save the result of the multiply
	for (int i = 0; i < m; i++)
		temp[i] = new double[a.n];
	for(int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = 0;
		}

	for (int i = 0; i < m; i++) 
	{
		for (int j = 0; j < a.n; j++)
		{
			temp[i][j] = 0;
			for (int k = 0; k < n; k++)
				temp[i][j] +=valueMT[i][k] * a.valueMT[k][j];
		}
	}
	this->~Matrix();//delete old matrix;
	// resize matrix
	m = m;
	n = a.n;
	valueMT = temp; // assign the result to matrix
	return 1;
}

double d = 0;
double det(int n, double ** matrix)
{
	int c, h, i, j, k;
	double** temp;
	//create an tempory array
	temp = new double *[n]; // create n rows
	for (int i = 0; i < n; i++)
		temp[i] = new double[n]; // create n cols

	if (n == 1) return matrix[0][0];

	if (n == 2)
	{
		return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	}
	else
	{
		//c=col, r=rowdd
	
		for (c = 0; c < n; c++)
		{
			h = 0;
			for (i = 1; i < n; i++)
			{
				k = 0;
				for (j = 0; j < n; j++)
				{
					if (j != c) {
						temp[h][k] = matrix[i][j];
						k++;
					}
				}
				h++;
			}
			d = d + (pow(-1, c) * matrix[0][c] * det(n - 1, temp));
		}
	}
	return d;

}
double Matrix::determinant()
{
	if (m != n) return -99; else return det(n, valueMT);
}

void Matrix::Cofactor(double**&temp, int p, int q, int n)//
{
	int i = 0, j = 0;
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{

			if (row != p && col != q)
			{
				temp[i][j++] = valueMT[row][col];
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}
double** Matrix::adjoint()
{
	double** adj;
	adj = new double *[n]; // create n rows
	for (int i = 0; i < n; i++)
	{
		adj[i] = new double[n]; // create n cols
	}
	if (n == 1)
	{
		adj[0][0] = 1;
		return adj;
	}

	int k = 1;
	double** temp;

	temp = new double *[n]; // create n rows
	for (int i = 0; i < n; i++)
		temp[i] = new double[n]; // create n cols


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Cofactor(temp, i, j, n);

			if ((i + j) % 2 == 0) k = 1; else k = -1;

			adj[j][i] = k*(det(n - 1, temp));
		}
	}
	return adj;
	
}
void Matrix::Inverse(double deter)
{
	double** temp;
	
	if (deter == 0||n!=m)
	{
		cout << "Can not find Inverse matrix";
		return;
	}
	else
	{
		// Find Inverse using  inverse[i][j]= adj[i][j]/det" 
		temp = new double *[n]; // create m rows
		for (int i = 0; i < n; i++)
			temp[i] = new double[n]; // create n cols
		double** adj = this->adjoint();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				temp[i][j] = adj[i][j] / deter;
				cout << temp[i][j] * 100 / 100<<"  " ;
			}
			cout << endl;
		}
	}

}

void swap(double** matrix, int row_1, int row_2, int col)//swap row_1 and row_2
{
	for (int i = 0; i < col; i++)
	{
		double temp = matrix[row_1][i];
		matrix[row_1][i] = matrix[row_2][i];
		matrix[row_2][i] = temp;
	}
}
int Matrix::Rank()
{	
	double tmp;//temporary var
	int rank = m;//numbers of row;
	if (n == 1) return 1;
	for (int r = 0; r < rank; r++)//r=row
	{
		for(int _tmp=0;_tmp<r-1;_tmp++)
			if (valueMT[r][_tmp] != 0)
			{
				continue;
			}
		if (valueMT[r][r]!=0)
		{
			for (int c = 0; c < rank; c++)//c:colunm
			{
				if (r != c)
				{
					tmp =valueMT[c][r] / valueMT[r][r];
					for (int i = 0; i < rank; i++)
						valueMT[c][i] -= tmp * valueMT[r][i];
				}
			}
		}
		else
		{
			int key = 1;
			for (int i = r + 1; i < m; i++)
			{
				if (valueMT[i][r]==0)
				{
					swap(valueMT, r, i, rank);
					key = 0;
					break;
				}
			}
			if (key == 1)
			{
				rank--;
				for (int i = 0; i < m; i++)
					valueMT[i][r] = valueMT[i][rank];

			}
		}
	}
	return rank;
}
void Matrix::Gauss(double* &b)
{
	double tmp;//temporary var
	int rank = m;//numbers of row;2
	for (int r = 0; r < rank; r++)//r=row
	{
		for (int _tmp = 0; _tmp < r - 1; _tmp++)
			if (valueMT[r][_tmp] != 0)
			{
				continue;
			}
		if (valueMT[r][r] != 0)
		{
			for (int c = 0; c < rank; c++)//c:colunm
			{
				if (r != c)
				{
					tmp = valueMT[c][r] / valueMT[r][r];
					for (int i = 0; i < rank; i++)
					{
						valueMT[c][i] -= tmp * valueMT[r][i];//dong c=-tmp*dong r;
					}
					b[c] -= tmp * b[r];
				}
			}
		}
		else
		{
			int key = 1;
			for (int i = r + 1; i < m; i++)
			{
				if (valueMT[i][r] == 0)
				{
					swap(valueMT, r, i, rank);

					double t = b[r];
					b[r] = b[i];
					b[i] = t;

					key = 0;
					break;
				}
			}
			if (key == 1)
			{
				rank--;
				for (int i = 0; i < m; i++)
					valueMT[i][r] = valueMT[i][rank];
				b[r] = b[rank];

			}
		}
	}
	cout << "B after using Gauss:" << endl;
	for (int i = 0; i < rank; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	
}
void Matrix::System_of_Linear_Equations(int r)
{
	double* x = new double[n];//solutions array
	double* b = new double[n];//constant terms array
	int i;
	cout << "Enter constant terms:" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "B[" << i << "]=";
		cin >> b[i];
	}
	if (r < n)
	{
		cout << "The equation has no solution";
		return;
	}
	this->Gauss(b);
	cout << "Matrix after using Gauss: " << endl;
	this->OutPut();
	for (i = r - 1; i >= 0; i--)
	{
		x[i] = b[i]/valueMT[i][i];
	}
	cout << " Solutions: ";
	for (i = 0; i < n; i++)
	{
		cout << x[i]*1000/1000 << "    ";
	}
}