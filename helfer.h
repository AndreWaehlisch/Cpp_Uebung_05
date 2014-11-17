#ifndef _HELFER_H
#define _HELFER_H

template < class T > T MAX (T a, T b)
{
  return a > b ? a : b;
}

template < class T > T MIN (T a, T b)
{
  return a < b ? a : b;
}

template < class T > void
SWAP (T & a, T & b)
{
  T c;
  c = a;
  a = b;
  b = c;
}

template < class T > T SIGN (T a, T b)
{
  return a >= 0 ? (b >= 0 ? a : -a) : (b >= 0 ? -a : a);
}
#endif
