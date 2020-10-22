#ifndef HISTOGRAM_H
#define HISTOGRAM_H
#include <iostream>
#include <cstdlib>


class Histogram
{

private:
  int num_bins;
  float* array;
  int array_size;
  float* bin_values;
  int* bin_frequencies;

public:
  Histogram(int num_bins, float *array, int array_size);
  ~Histogram();
  Histogram(const Histogram &other);

  void solve();

  float* getValues();
  int* getFrequencies();

  void setBinValues(float* bin_values);
  void setBinFrequencies(int* bin_frequencies);

};

#endif
