#include <iostream>
#include <cmath>
#include "helfer.h"
using namespace std;

int
main ()
{
  int a = 1, b = 2;
  double c = 1.2, d = 1.3;

  cout << "Max (" << a << ", " << b << ") = " << MAX (a, b) << endl;
  cout << "Max (" << c << ", " << d << ") = " << MAX (c, d) << '\n' << endl;

  cout << "Min (" << a << ", " << b << ") = " << MIN (a, b) << endl;
  cout << "Min (" << c << ", " << d << ") = " << MIN (c, d) << '\n' << endl;

  cout << "a = " << a << ", b = " << b << endl;
  cout << "SWAP ( a, b )" << endl;
  SWAP (a, b);
  cout << "a = " << a << ", b = " << b << '\n' << endl;

  cout << "c = " << c << ", d = " << d << endl;
  cout << "SWAP ( c, d )" << endl;
  SWAP (c, d);
  cout << "c = " << c << ", d = " << d << '\n' << endl;

  cout << "SIGN (" << a << ", " << b << ") = " << SIGN (a, b) << endl;
  cout << "SIGN (" << -a << ", " << b << ") = " << SIGN (-a, b) << endl;

  cout << "SIGN (" << c << ", " << -d << ") = " << SIGN (c, -d) << endl;
  cout << "SIGN (" << -c << ", " << -d << ") = " << SIGN (-c, -d) << endl;
}
