#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "Histogram.h"

using namespace std;

class Histogram
{
private:
  int num_bins;
  float* array;
  int array_size;
  float* bin_values;
  float* bin_frequencies;

public:
  Histogram(float *array = NULL, int array_size = 0, int num_bins = 10);
  ~Histogram();
  Histogram(const Histogram &h);
  friend ostream & operator << (ostream &cout, const Histogram &h);

  void solve();

  float* getValues();
  float* getFrequencies();
  int getNumBins();

  void setBinValues(float* bin_values);
  void setBinFrequencies(float* bin_frequencies);

};

#endif
