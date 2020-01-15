#include <iostream>
#include "sqMatrix.h"

using namespace std;

int main()
{
	sqMatrix D(4);
	D.show();
	D.get();
	double Y[] = { 1, 2, 3, 4 };
	D.GaussianElimination(Y);
	sqMatrix A(2);
	A.show();
	A.get();
	A.show();
	sqMatrix B(2);
	B.get();
	B.show();
	B.transpose();
	B.show();
	(A - B).show();
	(A - 5.7).show();
	(A + 3.4).show();
	A = 3.2;
	A.show();
	B.show();
	A += B;
	A.show();
	A += 4.1;
	A.show();
	A -= B;
	A.show();
	A -= 5.0;
	A.show();
	B.show();
	sqMatrix C(2);
	C = A + B;
	C.show();
	A.show();
	C = A + 3.2;
	C.show();
	A.show();
	C = A - 2.1;
	C = 5.1 + A;
	C.show();
	C = 10.0 - A;
	C.show();

	return 0;
}
