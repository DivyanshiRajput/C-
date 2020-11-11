#ifndef FIVENUMBERSUMMARY_H
#define FIVENUMBERSUMMARY_H

#include <cstddef>
#include "FiveNumberSummary.h"

using namespace std;

class FiveNumberSummary
{
private:
  float min;
  float max;
  float median;
  float lower_quartile;
  float upper_quartile;
  float*  sequence;
  int size;

public:
  FiveNumberSummary(int size = 0, float* s = NULL);
  ~FiveNumberSummary();
  FiveNumberSummary(const FiveNumberSummary &fns);
  friend ostream & operator << (ostream &cout, const FiveNumberSummary &fns);
  float getMin();
  float getLowerQuartile();
  float getMedian();
  float getUpperQuartile();
  float getMax();
};

#endif
