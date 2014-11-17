#include "datum.h"
using namespace std;

int
main ()
{
  Datum d1;
  Datum d2 (1);
  Datum d3 (2, 3);
  Datum d4 (5, 6, 2007);

  cout << "Aktuelles Datum: " << d1 << endl;
  cout << "1. Tag des aktuellen Monats: " << d2 << endl;
  cout << "2. Tag im März des aktuellen Jahres: " << d3 << endl;
  cout << "Das Datum 05.06.2007: " << d4 << endl;

  // Die Datum.weekday Funktion ist nur für Wochentage ab dem Jahr 1583 gültig. Wird ein Datum davor angefordert, produziert dies einen Fehler der hier abgefangen wird.
  try
  {
    Datum d5 (1, 1, 1582);

    cout << "Datum vor dem Jahr 1583: " << d5.weekday () << endl;	// wird nicht mehr ausgegeben!
  }
  catch (const char *e)
  {
    cout << "ERROR: '" << e << "'" << endl;
  }
}
