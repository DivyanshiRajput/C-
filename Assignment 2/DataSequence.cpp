#include<iostream>
#include<cstdlib>
#include "DataSequence.h"
#include "Histogram.h"

using namespace std;

//constructor
DataSequence:: DataSequence(int size, float* values)
    :size(size)
    {
        this->sequence = new float[size];

        for(int i = 0; i < size; i++)
        {
          this->sequence[i] = values[i];
        }
    this->sort(sequence, size);
}

//destructor
DataSequence:: ~DataSequence()
{
  delete[] sequence;
}

//sorting function
void DataSequence:: sort(float* sequence, int size)
{
    for (int i = 0; i < size-1; i++)
    {
      for (int j = 0; j < size-i-1; j++)
      {
        if (sequence[j] > sequence[j+1])
        {
          float temp = sequence[j];
          sequence[j] = sequence[j+1];
          sequence[j+1] = temp;
        }
      }
    }
    this->min = sequence[0];
    this->max = sequence[size-1];
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
      sum += *(sequence+i);
    }
    this->mean = sum/size;
    if (size%2 == 1)
    {
      this->median = sequence[(size)/2];
    }
    else
    {
      this->median = (sequence[(size)/2] + sequence[(size-1)/2])/2;
    }
}

//getters
float DataSequence:: getMean()
{
  return mean;
}

float DataSequence:: getMedian()
{
  return median;
}

float DataSequence:: getMin()
{
  return min;
}

float DataSequence:: getMax()
{
  return max;
}

Histogram DataSequence:: genHistogram(int n)
{
  return Histogram(n, sequence, size);
}
