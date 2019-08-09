//
// calculator.cpp
//
// DO NOT MODIFY THIS FILE
//

#include "Fraction.h"
#include<iostream>
#include<stdexcept>
using namespace std;

int main()
{
  Fraction x,y;
  char op;
  try
  {
    cin >> x;
    cin >> op;
    while ( cin && ( op == '+' || op == '-' ) )
    {
      cin >> y;
      if ( op == '+' )
        x = x + y;
      else
        x = x - y;
      cin >> op;
    }
    cout << x << endl;
  }
  catch ( invalid_argument& e )
  {
    cout << "Error: " << e.what() << endl;
  }
}
