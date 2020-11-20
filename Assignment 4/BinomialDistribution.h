#ifndef BINOMIALDISTRIBUTION_H
#define BINOMIALDISTRIBUTION_H
#include <iostream>
#include "Histogram.h"

class BinomialDistribution: public Histogram
{
private:
  int n;
  float p;
  double factorial(int n);

public:
  BinomialDistribution(int n, float p);
};

#endif
