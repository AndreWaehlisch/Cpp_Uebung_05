#include <iostream>
using namespace std;

template < class T > class Matrix
{
private:

  T v[3][3];

public:
  //Erster Konstruktor
  Matrix ()
  {
    for (int i = 0; i < 9; i++)
      v[i / 3][i % 3] = 0.0;
  }
  // Zweiter Konstruktor
  Matrix (const T a[3][3])
  {
    for (int i = 0; i < 9; i++)
      v[i / 3][i % 3] = a[i / 3][i % 3];
  }

  const T *operator[] (int i) const
  {
    if (i < 3)
      return v[i];
    else
      return NULL;
  }

  T *operator[] (int i)
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

int
main ()
{
  double a[3][3] = { {1.1, 2.2, 3.3},
  {4.4, 5.5, 6.6},
  {7.7, 8.8, 9.9}
  };

  int b[3][3] = { {1, 1, 1},
  {1, 1, 1},
  {1, 1, 1}
  };


  Matrix < double >m (a);
  Matrix < int >n (b);

  cout << "double: m = \n" << m << endl;
  cout << "\nint: n = \n" << n << endl;

}
