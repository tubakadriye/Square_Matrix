
class sqMatrix
{
private:
	int M;
	double** array2d;

public:

	sqMatrix(int N);
	sqMatrix(sqMatrix& A);
	~sqMatrix();
	void get();
	void show();
	sqMatrix transpose();
	sqMatrix operator +(const sqMatrix& other);
	sqMatrix operator -(sqMatrix& other);
	sqMatrix operator +(double a);
	sqMatrix& operator -(double a);
	sqMatrix& operator = (const sqMatrix& other);
	//sqMatrix& operator =(sqMatrix& other);
	sqMatrix operator =(double c);
	sqMatrix operator +=(sqMatrix& other);
	sqMatrix operator +=(double a);
	sqMatrix operator -=(sqMatrix& other);
	sqMatrix operator -=(double c);
	friend sqMatrix operator +(double value, const sqMatrix& C);
	friend sqMatrix operator -(double value, const sqMatrix& C);
	double* GaussianElimination(double* Y);

};
