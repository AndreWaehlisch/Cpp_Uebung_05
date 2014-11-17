#include <iostream>
using namespace std;

class Matrix
{
private:

  double v[3][3];

public:
  //Erster Konstruktor
    Matrix ()
  {
    for (int i = 0; i < 9; i++)
      v[i / 3][i % 3] = 0.0;
  }
  // Zweiter Konstruktor
  Matrix (const double a[3][3])
  {
    for (int i = 0; i < 9; i++)
      v[i / 3][i % 3] = a[i / 3][i % 3];
  }

  const double *operator[] (int i) const
  {
    if (i < 3)
      return v[i];
    else
      return NULL;
  }
  double *operator[] (int i)
  {
    if (i < 3)
      return v[i];
    else
      return NULL;
  }

  friend ostream & operator<< (ostream & out, const Matrix & m)
  {

    out << '[';
    for (int i = 0; i < 9; i++)
      {
	if (i % 3)
	  out << ',';
	else if (i != 0)
	  out << "]\n[";
	out << m[i / 3][i % 3];
      }
    out << ']';

    return out;
  }

};

Matrix
matAdd (const Matrix & a, const Matrix & b)
{
  Matrix m (a);

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      m[i][j] += b[i][j];

  return m;
}


Matrix
matMult (const Matrix & a, const Matrix & b)
{
  Matrix m;

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
	m[i][j] += a[i][k] * b[k][j];

  return m;
}

int
main ()
{
  double a[3][3] = { {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9}
  };

  double b[3][3] = { {1, 1, 1},
  {1, 1, 1},
  {1, 1, 1}
  };


  Matrix m (a);
  Matrix n (b);

  cout << "m[1][2] = " << m[1][2] << '\n' << endl;

  cout << "\nm = \n" << m << endl;
  cout << "\nn = \n" << n << endl;
  cout << "\nm+m = \n" << matAdd (m, m) << endl;
  cout << "\nn+n = \n" << matAdd (n, n) << endl;
  cout << "\nm+n = \n" << matAdd (m, n) << endl;
  cout << "\nm*m = \n" << matMult (m, m) << endl;
  cout << "\nn*n = \n" << matMult (n, n) << endl;
  cout << "\nm*n = \n" << matMult (m, n) << endl;
  cout << "\nm*m = \n" << matMult (n, m) << endl;

  //Die Berechnungen sind alle korrekt.
}
