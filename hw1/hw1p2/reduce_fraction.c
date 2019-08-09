/* find gcd of two numbers */
int find_gcd (int n1, int n2) 
{
  int gcd, remainder;

  /* Euclid's algorithm */
  remainder = n1 % n2; 
  while ( remainder != 0 )
  {
    n1 = n2;
    n2 = remainder; 
    remainder = n1 % n2; 
  } 
  gcd = n2; 

  return gcd;
}

/* reduce a fraction */
void reduce_fraction(int *nump,  int *denomp) 
{
  int gcd;   
  gcd = find_gcd(*nump, *denomp);
  *nump = *nump / gcd;
  *denomp = *denomp / gcd;
}
