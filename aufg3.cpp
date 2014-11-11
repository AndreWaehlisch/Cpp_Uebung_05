#include <iostream>
#include <cmath>
using namespace std;

class Vektor {

	double *ar;

 public:

	int N;

	 Vektor(const int n) {
		N = n;
		ar = new double[N];
	} Vektor(const int n, const double input[]) {
		N = n;
		ar = new double[n];

		for (int i = 0; i < N; i++) {
			ar[i] = input[i];
		}
	}

	Vektor(const Vektor & v) {
		N = v.N;

		ar = new double (N);

		for (int i = 0; i < N; i++) {
			ar[i] = *v[i];
		}
	}

	// Destruktor: Wird in erster Linie benutzt, um Speicher wieder freizugeben.
	~Vektor() {
		delete[]ar;
	}

	const double *operator[] (const int i)const {
		return &ar[i];
	} double *operator[] (const int i) {
		return &ar[i];
	}
};

const Vektor vektorsumme(const Vektor v1, const Vektor v2)
{
	Vektor c(v1);

	for (int i = 0; i < c.N; i++) {
		*c[i] = *v1[i] + *v2[i];
	}

	return c;
}

int main()
{
	const double i[4] = { 1, 2, 3, 4 };
	const Vektor c1(4, i);
	const Vektor c2(4, i);

	const Vektor c3(vektorsumme(c1, c2));

	cout << *c3[1] << endl;
}
