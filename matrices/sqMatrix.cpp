#include "sqMatrix.h"
#include <iostream>

using namespace std;

sqMatrix::sqMatrix(int N)
{
	M = N;
	array2d = new double* [M];

	for (int i = 0; i < M; i++, cout << endl)
	{
		array2d[i] = new double[M];
		for (int j = 0; j < M; j++)
		{
			array2d[i][j] = 0.00;

		}
	}

}

sqMatrix::sqMatrix(sqMatrix& A)
{
	cout << "copy constructor" << endl;
	M = A.M;
	array2d = new double* [M];

	for (int i = 0; i < M; i++)
	{
		array2d[i] = new double[M];
		for (int j = 0; j < M; j++)
		{
			array2d[i][j] = A.array2d[i][j];
		}
	}
}


sqMatrix::~sqMatrix()
{
	for (int i = 0; i < M; i++)
	{
		delete array2d[i];
	}
	cout << "deconstructor hello" << endl;

	delete array2d;
}


void sqMatrix::get()
{
	cout << "Enter N: ";
	cin >> M;
	cout << "Enter matrix elements: \n";
	for (int i = 0; i < M; i++)
	{

		for (int j = 0; j < M; j++)
		{
			cin >> array2d[i][j];
		}
	}
}

void sqMatrix::show()
{
	cout << "The matrix is: \n";
	for (int i = 0; i < M; i++)
	{
		cout << "\t  " << i;
	}

	cout << "\t " << endl;

	for (int i = 0; i < M; i++, cout << endl)
	{
		cout << i << "\t ";
		for (int j = 0; j < M; j++)
		{
			cout << array2d[i][j] << "\t  ";
		}
	}
}

sqMatrix sqMatrix::transpose()
{
	double temp;
	temp = 0;
	//sqMatrix Transpose (M);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < i; j++)
		{
			//Transpose.array2d[i][j] = array2d[j][i];
			double tmp = array2d[i][j];
			array2d[i][j] = array2d[j][i];
			array2d[j][i] = tmp;

			//swap(array2d[i][j], array2d[j][i]);
		}
	}

	//*this = Transpose;

	return *this;

}

sqMatrix sqMatrix::operator+(const sqMatrix& other)
{
	sqMatrix A(M);
	if (M != other.M) {
		printf("Dimensions do not match!!!!");
		exit(0);
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			A.array2d[i][j] = array2d[i][j] + other.array2d[i][j];
		}
	}

	return A;
}

sqMatrix sqMatrix::operator-(sqMatrix& other)
{
	sqMatrix B(M);
	if (M != other.M) {
		printf("Dimensions do not match!!!!");
		exit(0);
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			B.array2d[i][j] = array2d[i][j] - other.array2d[i][j];
		}
	}

	return B;
}

sqMatrix sqMatrix::operator+(double a)
{
	sqMatrix B(M);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			B.array2d[i][j] = this->array2d[i][j] + a;
		}
	}
	return B;
}

sqMatrix& sqMatrix::operator-(double b)
{
	sqMatrix T(M);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			T.array2d[i][j] = this->array2d[i][j] - b;
		}
	}
	return T;
}

sqMatrix& sqMatrix::operator=(const sqMatrix& other)
{
	if (M != other.M) {
		printf("Dimensions do not match!!!!");
		exit(0);
	}
	else {

		if (array2d != NULL) {

			for (int i = 0; i < M; i++)
			{
				delete array2d[i];
			}

			delete array2d;
		}

		cout << "assignment operator " << endl;
		M = other.M;
		array2d = new double* [other.M];
		for (int i = 0; i < other.M; i++)
		{
			array2d[i] = new double[other.M];

			for (int j = 0; j < other.M; j++)
			{
				array2d[i][j] = other.array2d[i][j];
			}
		}

		return *this;
	}
}

sqMatrix sqMatrix::operator=(double c)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			array2d[i][j] = c;
		}
	}
	return *this;
}

sqMatrix sqMatrix::operator+=(sqMatrix& other)
{
	if (M != other.M) {
		printf("Dimensions do not match!!!!");
		exit(0);
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			array2d[i][j] += other.array2d[i][j];

		}

	}

	return *this;

}

sqMatrix sqMatrix::operator+=(double a)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			array2d[i][j] += a;
		}
	}
	return *this;
}

sqMatrix sqMatrix::operator-=(sqMatrix& other)
{
	if (M != other.M) {
		printf("Error!!!!");
		exit(0);
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			array2d[i][j] -= other.array2d[i][j];
		}
	}

	return *this;
}

sqMatrix sqMatrix::operator-=(double c)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			array2d[i][j] -= c;
		}
	}
	return *this;

}

double* sqMatrix::GaussianElimination(double* Y)
{
	double* X;
	X = new double[M];
	for (int i = 0; i < M; i++) {
		// search for max in this column
		double max = abs(array2d[i][i]);
		int p = i;
		for (int k = i + 1; k < M; k++) {
			if (abs(array2d[k][i]) > max) {
				max = abs(array2d[k][i]);
				p = k;
			}
		}
		this->show();

		// Swap max row with the current row (column by column)
		for (int k = i; k < M + 1; k++)
		{
			double tmp = array2d[p][k];
			array2d[p][k] = array2d[i][k];
			array2d[i][k] = tmp;
			tmp = Y[p];
			Y[p] = Y[i];
			Y[i] = tmp;

		}
		this->show();

		//Make all rows below this one 0 in current column
		for (int k = i + 1; k < M; k++)
		{
			double factor = -array2d[k][i] / array2d[i][i];
			for (int j = i; j < M + 1; j++)
			{
				if (i == j) {
					array2d[k][j] = 0;
				}
				else {
					array2d[k][j] += factor * array2d[i][j];

				}

				Y[k] = Y[k] + factor * Y[i];
			}
		}
	}
	this->show();

	//Backward Substitution

	for (int i = M - 1; i > 0; i--)
	{
		double sum = 0.0;
		for (int j = i + 1; j < M + 1; j++)
		{
			sum = sum + array2d[i][j] * X[j];
		}
		X[i] = (Y[i] - sum) / array2d[i][i];
	}


	for (int i = 0; i < M; i++)
	{
		cout << "X[i]" << X[i] << endl;
	}

	return X;
}

sqMatrix operator+(double value, const sqMatrix& C)
{
	sqMatrix A(C.M);
	for (int i = 0; i < C.M; i++)
	{
		for (int j = 0; j < C.M; j++)
		{
			A.array2d[i][j] = value + C.array2d[i][j];
		}
	}
	return A;
}

sqMatrix operator-(double value, const sqMatrix& C)
{
	sqMatrix A(C.M);
	for (int i = 0; i < C.M; i++)
	{
		for (int j = 0; j < C.M; j++)
		{
			A.array2d[i][j] = value - C.array2d[i][j];
		}
	}
	return A;
}

//sqMatrix& sqMatrix::operator = (sqMatrix &other) {
//	for (int i = 0; i < M; i++)
//	{
//		array2d[i] = new double[M];
//
//		for (int j = 0; j < M; j++)
//		{
//			array2d[i][j] = other.array2d[i][j];
//		}
//	}
//}


