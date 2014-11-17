#include <iostream>
#include <cmath>
using namespace std;

class Vektor {

 private:

	double *ar;

 public:

	int N;

	 Vektor(const int n) {
		N = n;
		ar = new double[N];
	} Vektor(const int n, const double input[]) {
		N = n;
		ar = new double[N];

		for (int i = 0; i < N; i++) {
			ar[i] = input[i];
		}
	}

	Vektor(const Vektor & v) {
		N = v.N;

		ar = new double[N];

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
	Vektor c(v1.N);

	for (int i = 0; i < c.N; i++) {
		*c[i] = *v1[i] + *v2[i];
	}

	return c;
}

int main()
{
	const int L = 1000;	// Ungefähr bei einer Array-Länge von 1048000 beendet das Programm mit der Fehlermeldung "Segmentation fault", was auf eine Zugriffsverletzung hinweist, da zu viel Speicher angefordert wird.

	double init[L];

	for (int k = 0; k < L; k++) {
		init[k] = k;
	}

	const Vektor c1(L, init);
	const Vektor c2(L, init);
	const Vektor c3(vektorsumme(c1, c2));

	cout << "1. Eintrag von Vektor c1 und c2: " << *c1[1] << endl;
	cout << "1. Eintrag der Vektorsumme: " << *c3[1] << endl;

	cout << "Letzter Eintrag von Vektor c1 und c2: " << *c1[L - 1] << endl;
	cout << "Letzter Eintrag der Vektorsumme: " << *c3[L - 1] << endl;
}
