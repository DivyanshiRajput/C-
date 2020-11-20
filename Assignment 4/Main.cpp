#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
#include<vector>

#include "Histogram.h"
#include "BinomialDistribution.h"

using namespace std;

int main()
{
  vector<string> arr;
  string input, temp;
  getline(cin, input);
  stringstream ss(input);
  
  while (getline(ss,temp,' '))
  {
    //splitting with spaces
    arr.push_back(temp);
  }
  if (arr.size() != 3)
  {
    cout << "-1" << endl;
    return 0;
  }
  int n = stoi(arr[0]);
  float p1 = stof(arr[1]);
  float p2 = stof(arr[2]);

  if (p1 > 1 || p2 > 1 || n < 1 || p1 < 0 || p2 < 0)
  {
    cout << "-1" << endl;
    return 0;
  }

  BinomialDistribution b1(n, p1);
  BinomialDistribution b2(n, p2);
  compare(b1, b2);
  return 0;
}
