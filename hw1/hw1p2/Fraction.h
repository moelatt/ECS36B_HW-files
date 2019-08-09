// Moe Ko Latt
// ID: 915866164
#ifndef Fraction_h
#define Fraction_h
#include <iostream>
using namespace std;

class Fraction
{
public:
//Functions
Fraction();
Fraction(int,int);
   int getNum() const;
   int getDen() const;
   void setNum(int num);
   void setDen(int den);
   void setChar(char ch);
   void reduce();
   void signs();

   friend ostream& operator<<(ostream &out,const Fraction &);
   friend istream& operator>>(istream &,Fraction &);
   Fraction operator+(const Fraction );
   Fraction operator-(const Fraction);
   Fraction& operator=(const Fraction);
private:
int num;
char ch;
int den;
};
#endif