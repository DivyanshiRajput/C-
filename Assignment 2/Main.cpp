#include<iostream>
#include<string.h>
#include "DataSequence.h"

using namespace std;

int main()
{
  int size,delimiter;
  char space[2];
  cin>>size;
  fgets(space,2,stdin);
  if(!strcmp(space,"  ") || strlen(space)<1 || space[0]=='\n')
  {
    cout<<-1;
    return 0;
  }
  cin>>delimiter;
  if(size<1 || delimiter!=-1)
  {
    cout<<-1;
    return 0;
  }
  fgets(space,2,stdin);
  if(!strcmp(space,"  ") || strlen(space)<1 || space[0]=='\n')
  {
    cout<<-1;
    return 0;
  }
  float array[size];
  char c;
  for(int i=0;i<size;i++)
  {
    cin>>array[i];
    scanf("%c",&c);
    if((i!=size-1 && c!=',') || (i==size-1 && c!=' ') || array[i]<=0)
    {
      cout<<-1<<endl;
      return 0;
    }
  }
  cin>>delimiter;
  if(delimiter!=-1)
  {
    cout<<-1;
    return 0;
  }
  fgets(space,2,stdin);
  if(!strcmp(space,"  ") || space[0]=='\n')
  {
    cout<<-1;
    return 0;
  }
  int num_bins;
  cin>>num_bins;
  if(num_bins<1)
  {
    cout<<-1;
    return 0;
  }
  char str[4];
  fgets(str,4,stdin);
  if(strcmp(str," -1")|| space[0]=='\n')
  {
    cout<<-1;
    return 0;
  }

  DataSequence seq(size, array);
  Histogram h = seq.genHistogram(num_bins);
  float* bin_values = h.getValues();
  int* bin_frequencies = h.getFrequencies();

  cout << seq.getMin() << " -1 " << seq.getMean() << " -1 " << seq.getMedian() << " -1 " << seq.getMax();
  cout << " -1 " << *(bin_values);
  for(int i = 1; i < num_bins + 1; i++)
  {
    cout<< "," << *(bin_values + i);
  }
  cout << " -1 " << *(bin_frequencies);
  for(int i = 1; i < num_bins; i++)
  {
		cout << "," << *(bin_frequencies + i);
  }
  cout << " -1";

  return 0;
}
