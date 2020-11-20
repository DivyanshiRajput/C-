#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "Histogram.h"

using namespace std;

class Histogram
{
protected:
  int num_bins;
  float* bin_values;

public:
  friend int compare(Histogram &h1, Histogram &h2);
  static float euclideanDistance(Histogram h1, Histogram h2);
  static float manhattanDistance(Histogram h1, Histogram h2);
  static float chebyshevDistance(Histogram h1, Histogram h2);
  static float klDivergence(Histogram h1, Histogram h2);
  static float jsDistance(Histogram h1, Histogram h2);
};

#endif
