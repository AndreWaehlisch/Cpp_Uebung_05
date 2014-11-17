#ifndef _DATUM_H_
#define _DATUM_H_

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

// **********
class Datum
{
private:

  int day, month, year;

public:

  // Constructor: day, month, & year
    Datum (const int dayIn = 17, const int monthIn = 11, const int yearIn = 2014)
  {
    day = dayIn;
    month = monthIn;
    year = yearIn;
  }

  friend ostream & operator<< (ostream & out, const Datum & d)
  {
    // Print the American date representation mm/dd/yyyy with leading zeros
    out << std::setfill ('0') << std::setw (2) << d.month << "/";
    out << std::setfill ('0') << std::setw (2) << d.day << "/";
    out << std::setfill ('0') << std::setw (2) << d.year;
    return out;
  }

  // Calculate the associated weekday provided that the year be greater than 1582
  const string & weekday ()
  {
    if (year <= 1582)
      throw ("Input parameter 'year' must be greater than 1582!");

    const int m = month < 3 ? month + 10 : month - 2;

    int c = year / 100;

    if (!(c % 4) && m > 10)
      --c;

    int y = year - 100 * c;

    if (m > 10)
      --y;

    const int d = day;
    const int w = int (d + int (2.6 * m - 0.2) + y + int (y / 4) + int (c / 4) - 2 * c) % 7;

    static const string name[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    return name[w];
  }
};

#endif
