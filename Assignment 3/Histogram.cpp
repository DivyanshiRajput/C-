#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>

#include "Histogram.h"

using namespace std;

inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }

//constructor
Histogram:: Histogram(float* array, int n, int nb)
:num_bins(nb),
array_size(n){
  this->bin_values = new float[num_bins+1];
  this->bin_frequencies = new float[num_bins];
  this->array = new float[array_size];

  for (int i = 0; i < array_size; i++)
  {
    this->array[i] = array[i];
  }

  for (int i = 0; i < num_bins; i++)
  {
    this->bin_frequencies[i] = 0.0;
  }
  this->solve();
}

//destructor
Histogram:: ~Histogram()
{
    delete[] bin_frequencies;
    delete[] bin_values;
    delete[] array;
}

//copy constructor
Histogram:: Histogram(const Histogram &h)
{
  num_bins = h.num_bins;
  array_size = h.array_size;
  bin_values = new float[num_bins+1];
  bin_frequencies = new float[num_bins];
  array = new float[array_size];

  for (int i = 0; i < num_bins + 1; i++)
  {
    bin_values[i] = h.bin_values[i];
  }

  for (int i = 0; i < num_bins; i++)
  {
    bin_frequencies[i] = h.bin_frequencies[i];
  }

  for (int i = 0; i < array_size; i++)
  {
    array[i] = h.array[i];
  }
}

//friend function
ostream & operator << (ostream &cout, const Histogram &h)
{
  float* bin_values = h.bin_values;
  float* bin_frequencies = h.bin_frequencies;
  cout << setprecision(4);
  cout << fixed;
  float temp = truncfunc(*(bin_values));
  cout << " " << temp;
  for(int i = 1; i < h.num_bins + 1; i++)
  {
    temp = truncfunc(*(bin_values + i));
    cout << "," << temp;
  }
  float temp2 = truncfunc(*(bin_frequencies));
  cout << " " << temp2;
  for(int i = 1; i < h.num_bins; i++)
  {
    temp2 = truncfunc(*(bin_frequencies + i));
    cout << "," << temp2;
  }
  return cout;
}

//solve function to calculate bin frequencies and bin values
void Histogram:: solve()
{
  float bin_width = (array[array_size-1] - array[0])/num_bins;

  //calculating bin values
  for(int i = 0; i < num_bins + 1; i++)
  {
    bin_values[i] = array[0] + i*bin_width;
  }

  //calculating bin frequencies
  for(int i=0; i < array_size; i++)
  {
    float temp = (array[i]-array[0])/bin_width;
    if( temp == num_bins)
    {
      bin_frequencies[num_bins-1] += 1.0/array_size;
    }
    else
    {
      bin_frequencies[int(temp)] += 1.0/array_size ;
    }
  }
}

//getters
float* Histogram::getValues()
{
  return bin_values;
}

float* Histogram::getFrequencies()
{
  return bin_frequencies;
}

int Histogram:: getNumBins()
{
  return this->num_bins;
}

//setters
void Histogram::setBinValues(float* values)
{
  this->bin_values = values;
}

void Histogram::setBinFrequencies(float* frequencies)
{
  this->bin_frequencies = frequencies;
}
