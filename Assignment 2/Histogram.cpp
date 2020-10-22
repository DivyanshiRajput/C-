#include "Histogram.h"
#include<cstdlib>
#include<iostream>
using namespace std;

//constructor
Histogram:: Histogram(int nb, float* array, int n)
:num_bins(nb),
array_size(n){
  this->bin_values = new float[num_bins+1];
  this->bin_frequencies = new int[num_bins];
  this->array = new float[array_size];

  for (int i = 0; i < array_size; i++)
  {
    this->array[i] = array[i];
  }

  for (int i = 0; i < num_bins; i++)
  {
    this->bin_frequencies[i] = 0;
  }
  this->solve();
}
//destructor
Histogram::~Histogram(){
    delete[] bin_frequencies;
    delete[] bin_values;
    delete[] array;
}

void Histogram:: solve()
{
  float bin_width = (array[array_size-1] - array[0])/num_bins;

  //calculating bin values
  for(int i=0;i<num_bins+1;i++)
  {
    bin_values[i] = array[0] + i*bin_width;
  }

  //calculating bin frequencies
  for(int i=0;i<array_size-1;i++)
  {
    float temp = (array[i]-array[0])/bin_width;
    bin_frequencies[int(temp)]++;
  }
  bin_frequencies[num_bins-1]++;

}

//getters
float* Histogram::getValues()
{
  return bin_values;
}

int* Histogram::getFrequencies()
{
  return bin_frequencies;
}

//setters
void Histogram::setBinValues(float* values)
{
  this->bin_values = values;
}

void Histogram::setBinFrequencies(int* frequencies)
{
  this->bin_frequencies = frequencies;
}
