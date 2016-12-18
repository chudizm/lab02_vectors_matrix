#include <iostream>
#include "vector.h"
#include "matrix.h"
//#include "utmatrix.h"
using namespace std;

void main()
{
	int size,sel;
	bool fillA = false, fillB = false;
	cout << "Enter the matrix order: ";
	do
		cin >> size;
	while ((size > MAX_MATRIX_SIZE)||(size < 1));
	matrix <int> A(size),B(size);
	do
	{
		system("cls");
		cout << "1. Input the A matrix" << endl
			 << "2. Input the B matrix" << endl
			 << "3. Output the A matrix" << endl
			 << "4. Output the B matrix" << endl
			 << "5. Output (A + B)" << endl
			 << "6. Output (A - B)" << endl
			 << "7. Output (A * B)" << endl
			 << "0. Exit" << endl << endl
			 << "Your command: ";
		cin >> sel;
		system("cls");
		switch(sel)
		{
		case 0: {break;}
		case 1:
			{
				cin >> A; fillA = true; break;
			}
		case 2:
			{
				cin >> B; fillB = true; break;
			}
		case 3:
			{
				fillA ? cout << A << endl : cout << "A matrix hasn't been inputed yet"; 
				cout << endl; break;
			}
		case 4:
			{
				fillB ? cout << B << endl : cout << "B matrix hasn't been inputed yet"; 
				cout << endl; break;
			}
		case 5:
			{
				(fillA && fillB) ? cout << (A+B) << endl : cout << "One of matrix haven't been inputed yet";
				cout << endl; break;
			}
		case 6:
			{
				(fillA && fillB) ? cout << (A-B) << endl : cout << "One of matrix haven't been inputed yet";
				cout << endl; break;
			}
		case 7:
			{
				(fillA && fillB) ? cout << (A*B) << endl : cout << "One of matrix haven't been inputed yet";
				/*if ((fillA)&&(fillB))
				{
					matrix <int> res(size);
					res = A * B;
					cout << res;
				}
				else cout << "One of matrix haven't been inputed yet";*/
				cout << endl; break;
			}
		}
		system("pause");
	}
	while (sel != 0);
}