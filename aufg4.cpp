#include <iostream>
using namespace std;

class Matrix {
 private:

	double v[3][3];

 public:
	//Erster Konstruktor
	 Matrix() {
		for (int i = 0; i < 9; i++)
			v[i / 3][i % 3] = 0.0;
	}
	// Zweiter Konstruktor Matrix(const double a[3][3]) {
		for (int i = 0; i < 9; i++)
			v[i / 3][i % 3] = a[i / 3][i % 3];
	}

	const double *operator[] (int i)const {
		if (i < 3)
			return v[i];
		else
			return NULL;
	} double *operator[] (int i) {
		if (i < 3)
			return v[i];
		else
			return NULL;
	}

	friend ostream & operator<<(ostream & out, const Matrix & m) {
		for (int i = 0; i < 9; i++) {

			if (i % 3)
				out << ',';
			else if (i != 0)
				out << '\n';

			out << m[i / 3][i % 3];
		}

		return out;
	}

};

Matrix matAdd(const Matrix & a, const Matrix & b)
{
	Matrix m(a);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m[i][j] += b[i][j];

	return m;
}

int main()
{
	double a[3][3] = { {1, 2, 3},
	{4, 5, 6},
	{7, 8, 9}
	};
	Matrix m(a);
	Matrix n;

	cout << "m[1][2] = " << m[1][2] << endl;

	cout << m << endl;

	n = matAdd(m, m);

	cout << matAdd(m, m) << endl;
}
