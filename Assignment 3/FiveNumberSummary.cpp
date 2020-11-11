#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>
#include<cstddef>

#include "FiveNumberSummary.h"

using namespace std;

inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }

//constructor
FiveNumberSummary:: FiveNumberSummary(int size, float* s)
:size(size)
{
  this->sequence = new float[size];
  for(int i = 0; i < size; i++)
  {
    this->sequence[i] = s[i];
  }

  //calculating minimum
  this->min = this->sequence[0];

  //calculating maximum
  this->max = this->sequence[this->size - 1];

  //calculating median
  if (size%2 == 1)
  {
    this->median = sequence[(size)/2];
  }
  else
  {
    this->median = (sequence[(size)/2] + sequence[(size-1)/2])/2;
  }

  float check = (((this->size) * 1.0) -1.0)/4; //size = 6 , 1 2 3 4 5 6

  //calculating lower quartile
  if(floor(check) == check)
  {
    this->lower_quartile = sequence[(size-1)/4];
  }
  else
  {
    int floorVal = floor(check);
    int ceilVal = floorVal+1;
    this->lower_quartile = (sequence[floorVal] + sequence[ceilVal])/2;
  }

  //calculating upper quartile
  if(floor(check*3) == check*3)
  {
    this->upper_quartile = sequence[3*size/4];
  }
  else
  {
    int floorVal = floor(check*3);
    int ceilVal = floorVal+1;
    this->upper_quartile = (sequence[floorVal] + sequence[ceilVal])/2;
  }

}

//destructor
FiveNumberSummary:: ~FiveNumberSummary()
{
  //delete[] sequence;
}

//copy constructor
FiveNumberSummary:: FiveNumberSummary(const FiveNumberSummary &fns)
{
  min = fns.min;
  max = fns.max;
  median = fns.median;
  lower_quartile = fns.lower_quartile;
  upper_quartile = fns.upper_quartile;
  size = fns.size;
  sequence = new float[size];

  for (int i = 0; i < size; i++)
  {
    sequence[i] = fns.sequence[i];
  }
}

//friend function
ostream & operator << (ostream &cout, const FiveNumberSummary &fns)
{
  cout << setprecision(4);
  cout << fixed;
  float min = fns.min;
  float lq = fns.lower_quartile;
  float median = fns.median;
  float uq = fns.upper_quartile;
  float max = fns.max;

  min = truncfunc(min);
  lq = truncfunc(lq);
  median = truncfunc(median);
  uq = truncfunc(uq);
  max = truncfunc(max);

  cout << min << "," << lq << "," << median << "," << uq << "," << max;
  return cout;
}

//getters
float FiveNumberSummary:: getMin()
{
  return this->min;
}

float FiveNumberSummary:: getLowerQuartile()
{
  return this->lower_quartile;
}

float FiveNumberSummary:: getMedian()
{
  return this->median;
}

float FiveNumberSummary:: getUpperQuartile()
{
  return this->upper_quartile;
}

float FiveNumberSummary:: getMax()
{
  return this->max;
}
