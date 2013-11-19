double fact(int n, double m)
{
  if(n == 0)
    return  m;
  else
    return fact(n-1, n*m);
}
