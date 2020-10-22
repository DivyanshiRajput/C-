#ifndef DATASEQUENCE_H
#define DATASEQUENCE_H
#include <iostream>
#include "DataSequence.h"
#include "Histogram.h"

class DataSequence
{
private:
  int size;
  float mean, median, min, max;
  float* sequence;

public:
  DataSequence(int size, float* sequence);
  ~DataSequence();
  DataSequence(const DataSequence &other);
  float getMax();
  float getMin();
  float getMean();
  float getMedian();
  void sort(float* sequence, int size);
  Histogram genHistogram(int nb);
};

#endif
