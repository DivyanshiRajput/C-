#ifndef DATASEQUENCE_H
#define DATASEQUENCE_H

#include "DataSequence.h"
#include "Histogram.h"
#include "FiveNumberSummary.h"

using namespace std;

class DataSequence
{
private:
  int size;
  float* sequence;
  FiveNumberSummary fns;
  Histogram* h;

public:
  DataSequence(int size, float* sequence);
  ~DataSequence();
  DataSequence(const DataSequence &other);
  friend ostream & operator << (ostream &cout, const DataSequence &ds);
  void sort(float* sequence, int size);
  void update(float* numbers, int n);
  FiveNumberSummary getFNS();
  Histogram getHistogram();
};

#endif
