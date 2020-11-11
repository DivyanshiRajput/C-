#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>

#include "DataSequence.h"

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
    this->fns = FiveNumberSummary(this->size, this->sequence);
    this->h = new Histogram(this->sequence, this->size);
}

//destructor
DataSequence:: ~DataSequence()
{
  delete[] sequence;
  this->h = NULL; // this is deleteiing the pointer of this DataSequence
}

//copy constructor
DataSequence:: DataSequence(const DataSequence &other)
{
  size = other.size;
  fns = other.fns;
  h = other.h;
  sequence = new float[size];
  for(int i = 0; i < size; i++)
  {
    sequence[i] = other.sequence[i];
  }
}

//friend function
ostream & operator << (ostream &cout, const DataSequence &ds)
{
  Histogram H = *(ds.h);
  FiveNumberSummary FNS = ds.fns;
  cout << FNS << H << " -1 ";
  return cout;
}

//sorting function using bubble sort algorithm
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
}

//update function
void DataSequence:: update(float* numbers, int n)
{
  int size = this->size + n;
  float* new_array = new float[size];
  for (int i = 0; i < this->size; i++)
  {
    new_array[i] = this->sequence[i];
  }

  for (int i = 0; i < n; i++)
  {
    new_array[this->size + i] = numbers[i];
  }
  delete[] this->sequence;
  this->h = NULL;
  this->sequence = new_array;
  this->size = size;
  this->sort(this->sequence, this->size);
  this->fns = FiveNumberSummary(this->size, this->sequence);
  this->h = new Histogram(this->sequence, this->size);
}

//getters
FiveNumberSummary DataSequence:: getFNS()
{
  return fns;
}

Histogram DataSequence:: getHistogram()
{
  return *h;
}
