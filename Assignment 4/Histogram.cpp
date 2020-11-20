#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>

#include "Histogram.h"

using namespace std;

inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }

//friend function
int compare(Histogram &h1, Histogram &h2)
{
  if (h1.num_bins != h2.num_bins)
  {
    cerr << "size not equal";
    return -1;
  }
  else
  {
    cout << setprecision(4);
    cout << fixed;

    float md = Histogram:: manhattanDistance(h1, h2);
    float ed = Histogram:: euclideanDistance(h1, h2);
    float cd = Histogram:: chebyshevDistance(h1, h2);
    float kl = Histogram:: klDivergence(h1, h2) + Histogram:: klDivergence(h2, h1);
    float js = Histogram::jsDistance(h1, h2);

    md = truncfunc(md);
    ed = truncfunc(ed);
    cd = truncfunc(cd);
    kl = truncfunc(kl);
    js = truncfunc(js);

    cout << md << " ";
    cout << ed << " ";
    cout << cd << " ";
    cout << kl << " ";
    cout << js << endl;
    return 1;
  }
}

//functions for calculating distances
float Histogram:: euclideanDistance(Histogram h1, Histogram h2)
{
  int n = h1.num_bins;
  float* v1 = h1.bin_values;
  float* v2 = h2.bin_values;
  float sum = 0; //stores the sum of squares of the difference of each component
  double result;
  for (int i = 0; i < n; i++) //loop for calculating sum
  {
    sum += pow(v2[i]-v1[i], 2); //calculates square of the term and add it to sum
  }
  result = sqrt(sum); //sqrt function for calculating root of sum

  return result;
}

float Histogram:: manhattanDistance(Histogram h1, Histogram h2)
{
  int n = h1.num_bins;
  float* v1 = h1.bin_values;
  float* v2 = h2.bin_values;
  float sum = 0;//stores ans i.e. the sum of absolute value of the difference of each component
  for (int i = 0; i < n; i++) //loop for calculating sum
  {
    sum += fabs(v2[i]-v1[i]); //using fabs function for calculating absolute of difference
  }

  return sum;
}

float Histogram:: chebyshevDistance(Histogram h1, Histogram h2)
{
  int n = h1.num_bins;
  float* v1 = h1.bin_values;
  float* v2 = h2.bin_values;
  float sum = v2[0] - v1[0]; //stores the answer which is the maximum of absolute difference between each component of the vectors
  for (int i = 1; i < n; i++) //updates sum according to the conditions
  {
     if (sum > (v2[i] - v1[i]))
     {
       continue;
     }
     else
     {
       sum = v2[i] - v1[i];
     }
  }
  return sum;
}

float Histogram:: klDivergence(Histogram h1, Histogram h2)
{
  int n = h1.num_bins;
  float* v1 = h1.bin_values;
  float* v2 = h2.bin_values;
  float sum = 0; //for storing sum of divergence of each component of the vector
  for (int i = 0; i < n; i++)
  {
    if (v1[i] != 0 && v2[i] != 0)
    {
      sum += v1[i] * log(v1[i]/v2[i]); //formula for calculating K.L. divergence
    }
    else
    {
      continue;
    }
  }

  return sum;
}

float Histogram:: jsDistance(Histogram h1, Histogram h2)
{
  int n = h1.num_bins;
  float* v1 = h1.bin_values;
  float* v2 = h2.bin_values;
  float m;
  float sum = 0; //for storing sum of divergence of each component of the vector
  for (int i = 0; i < n; i++)
  {
    if (v1[i] != 0 && v2[i] != 0)
    {
      m = (v1[i] + v2[i])/2 ;
      sum += 0.5 * (v1[i] * log(v1[i]/m));
      sum += 0.5 * (v2[i] * log(v2[i]/m));
    }
    else
    {
      continue;
    }
  }

  sum = sqrt(sum);

  return sum;
}
