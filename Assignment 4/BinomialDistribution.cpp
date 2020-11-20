#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>
#include<cmath>

#include "BinomialDistribution.h"

using namespace std;

//constructor
BinomialDistribution:: BinomialDistribution(int n, float p)
{
  this->num_bins = n+1;
  this->n = n;
  this->p = p;
  this->bin_values = new float[this->num_bins];
  for (int i = 0; i < num_bins; i++)
  {
    bin_values[i] = (factorial(n)/(factorial(n-i) * factorial(i))) * pow(p, i) * pow(1-p, n-i);
  }
}

//factorial function
double BinomialDistribution:: factorial(int n)
{
  if (n == 0)
  {
    return 1;
  }
  else if (n == 1)
  {
    return 1;
  }
  else
  {
    return n*factorial(n-1);
  }
}
