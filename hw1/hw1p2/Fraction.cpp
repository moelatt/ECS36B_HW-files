// Moe Ko Latt
// ID: 915866164
#include "Fraction.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Fraction::Fraction()
{
   setNum(0);
   setDen(1);
}
Fraction::Fraction(int a, int b)
{
   setNum(a);
   setDen(b);
   reduce();
}
void Fraction::setNum(int a)
{
   num = a;
}

void Fraction::setDen(int b)
{
   den = b;
}
void Fraction::setChar(char character){
   ch = character;
}
int Fraction::getNum() const
{
   return num;
}
int Fraction::getDen() const
{
   return den;
}
void Fraction::reduce()
{
   signs();
   int Sign = 1;
   int c = getNum();
   int d = getDen();
   if (c < 0)
   {
   c*= -1;
   Sign = -1;
   }
   for (int i = (c * d); i > 1; i--)
   {
   if ((c % i == 0) && (d % i == 0))
   {
   c /= i;
   d /= i;
   }
   }
   c *= Sign;
   setNum(c);
   setDen(d);
}
void Fraction::signs()
{
   int nem = getNum();
   int den = getDen();
   if (den < 0)
   {
   nem *= -1;
   den *= -1;
   }
   setNum(nem);
   setDen(den);
}
istream &operator>>(istream &in, Fraction &frac)
{
   int num;
   int den;
   char ch = '/';
   in >> num >> ch >> den;
   if (ch != '/'){
   	throw invalid_argument("malformed input exception character");
   }
   if (den == 0)
   {
   throw invalid_argument("zero denominator");
   exit(0);
   }
   frac.setNum(num);
   frac.setChar(ch);
   frac.setDen(den);
   frac.reduce();
   return in;
}
ostream &operator<<(ostream& out, const Fraction& frac)
{
	
  if (frac.getDen() == 1){
   out << frac.getNum();
}
   else if (frac.getNum() == 0){
      out<< frac.getNum();
   }
  else {
   out << frac.getNum() << "/" << frac.getDen() ;
   }
   return out;
}
Fraction Fraction::operator+(const Fraction frac)

{

   int Nsum = ((*this).getNum() * frac.getDen()) + (frac.getNum() * (*this).getDen());

   int Dsum = ((*this).getDen() * frac.getDen());

   Fraction frac2(Nsum, Dsum);

   frac2.reduce();

   return frac2;

}
Fraction Fraction::operator-(const Fraction frac)

{

   int Nminus = ((*this).getNum() * frac.getDen()) - (frac.getNum() * (*this).getDen());

   int Dminus = ((*this).getDen() * frac.getDen());

   Fraction frac3(Nminus, Dminus);

   frac3.reduce();

   return frac3;

}
Fraction &Fraction::operator=(const Fraction frac){
   int Nequal =  frac.getNum();
   int Dequal = frac.getDen();
   (*this).setNum(Nequal);
   (*this).setDen(Dequal);
   return *this;
}













