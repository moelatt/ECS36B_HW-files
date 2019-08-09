//
// useFraction.cpp
//
// DO NOT MODIFY THIS FILE
//

#include "Fraction.h"
#include<iostream>
using namespace std;

void print_fraction(const Fraction& f)
{
  cout << "print_fraction: " << f.getNum() << "/" << f.getDen() << endl;
}

int main()
{
  Fraction x(2,3);
  Fraction y(6,-2);

  cout << x << endl;
  cout << y << endl;

  cin >> y;
  cout << y << endl;
  print_fraction(y);
  Fraction z = x + y;
  cout << x << " + " << y << " = " << z << endl;
}
