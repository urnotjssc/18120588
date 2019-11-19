#include "Vector.h"
#include "Matrix.h"

int main()
{
	char ans = 'N';
	int key,temp_rank;
	double deter;
	Vector VT, TEMP, vt;
	Matrix mt, MT,temp,_temp;
	double** tmp;

	cout << "Hello!" << endl;
	do 
	{

		cout << "Press 1 if you want to work with vector" << endl;
		cout << "Press 2 if you want to work with matrix" << endl;
		cout << "---------------------------------------" << endl;

		cin >> key;
		switch (key)
		{
		case 1:

			vt.input();
			vt.output();
			//ở mỗi case ta sẽ tạo một biến VT có các thông số giống vt. Tương tự với matrix
			int keyVT;
			do 
			{
			cout << "Press 1 if you want to add 2 vector" << endl;
			cout << "Press 2 if you want to multiply vector to K" << endl;
			cout << "---------------------------------------" << endl;
				cout << "Enter a number: " << endl;
				cin >> keyVT;
				switch (keyVT)
				{

				case 1:
					VT = vt;
					cout << "Enter one more vector to make addition" << endl << endl;
					TEMP.input();
					TEMP.output();
					cout << "---------------------------------------" << endl;
					if (VT.add(TEMP) == 0) cout << "Can not make addition" << endl;
					else VT.output();
					break;
				case 2:
					VT = vt;
					cout << "Enter K:";
					int cst;
					cin >> cst;
					VT.multiplyK(cst);
					VT.output();
					break;

				default:
					cout << "Invalid number" << endl;
					break;
				}
			cout << endl << "Do you want to continue working with this vector (Y/N)?\n";
			cout << "You must type a 'Y' or an 'N' :";
			cin >> ans;
			} while ((ans == 'Y') || (ans == 'y'));
			break;

		case 2:

			mt.Input();
			mt.OutPut();
			do
			{
				cout << "Press 1 if you want to calculate matrix's determinant" << endl;
				cout << "Press 2 if you want to multiply 2 matrix" << endl;
				cout << "Press 3 if you want to find inverse matrix" << endl;
				cout << "Press 4 if you want to calculate matrix's rank" << endl;
				cout << "Press 5 if you want to find system of linear equations" << endl;
				cout << "---------------------------------------" << endl;
				int keyMT;
				cout << "Enter a number: " << endl;
				cin >> keyMT;

				switch (keyMT)
				{
				case 1:
					MT = mt;
					deter = MT.determinant();
					if (deter == -99) cout << "The matrix has no determinant " << endl;
					else cout << "Matrix's determinant: " << deter;
					break;
				case 2:
					MT = mt;
					temp.Input();
					temp.OutPut();
					if (MT.Multiply(temp) != 0) {

						cout << "Result of the Multiplication " << endl;
						MT.OutPut();
					}
					else cout << "Can not make the Multiplication";
					break;
				case 3:
					MT = mt;
					_temp = mt;
					deter = MT.determinant();
					_temp.Inverse(deter);
					break;
				case 4:
					MT = mt;
					cout << "Rank of matrix: " << MT.Rank() << endl;
					cout << "Matrix after using Gauss:" << endl;
					MT.OutPut();
					break;
				case 5:
					MT = mt;
					_temp = mt;

					temp_rank = _temp.Rank();//save value Rank of matrix MT& use Gauss changing matrix
				/*	cout << "Matrix after using Gauss:" << endl;
					_temp.OutPut();*/
					MT.System_of_Linear_Equations(temp_rank);

					break;
				default:
					break;
				}
				cout << endl << "Do you want to continue working with this matrix (Y/N)?\n";
				cout << "You must type a 'Y' or an 'N' :";
				cin >> ans;
			} while ((ans == 'Y') || (ans == 'y'));
			break;

		default:
			cout << "Invalid number" << endl;
			break;
		}
		cout <<endl<< "Do you want to stay (Y/N)?\n";
		cout << "You must type a 'Y' or an 'N' :";
		cin >> ans;
	} while ((ans == 'Y') || (ans == 'y'));
	
	system("pause");
	return 0;
}
