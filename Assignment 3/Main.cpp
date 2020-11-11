#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
#include<vector>

#include "DataSequence.h"

using namespace std;

int main()
{
  // got string tokens, separated by spaces
  string input;
  getline(cin, input);
  vector<string> tokens;
  stringstream check1(input);
  string intermediate;
  while(getline(check1, intermediate, ' ')) //splitting with spaces
  {
    tokens.push_back(intermediate);
  }

  vector<DataSequence> DSVector; // DataSequence vector

  while(!tokens.empty())
  {
    if (tokens[0][0] == 'N' && tokens[0][2] == '0')
    {
      tokens.erase(tokens.begin());

      if(tokens[0] == "-1")
      {
        tokens.erase(tokens.begin());
      }

      else
      {
        cout << -1 << endl;
        return 0;
      }
    }

    else if (tokens[0][0] == 'N' && tokens[0][2] != '0')  // if the size of sequence is not zero
    {
      tokens.erase(tokens.begin());
      string sequence = tokens[0];
      vector<float> v;
      stringstream check2(sequence);
      string intermediate;
      while(getline(check2, intermediate, ','))
      {
        v.push_back(stof(intermediate));
      }
      // create data sequence, store it in DSVector array
      DataSequence temp(v.size(), v.data());
      DSVector.push_back(temp);

      tokens.erase(tokens.begin());

      if(tokens[0] == "-1")
      {
        tokens.erase(tokens.begin());
      }

      else
      {
        cout << -1 << endl;
        return 0;
      }
    }

    else if (tokens[0][0] == 'A')
    {
      vector<float> add;
      // removing A and ',' ( comma ) from the string
      tokens[0].erase(tokens[0].begin());
      tokens[0].erase(tokens[0].begin());
      stringstream check2(tokens[0]);
      // splitting using comma
      while(getline(check2, intermediate, ','))
      {
        add.push_back(stof(intermediate)); // using stof to convert string to float
      }
      int index = (int)add[0];
      add.erase(add.begin());
      DSVector[index].update(add.data(), add.size());
      tokens.erase(tokens.begin());
      if(tokens[0] == "-1")
      {
        tokens.erase(tokens.begin());
      }
      else
      {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  //final loop for printing the output
  for (int j = 0; j < (int)DSVector.size(); j++)
  {
    DataSequence seq = DSVector[j];
    cout << seq;
  }
  cout << endl;
  return 0;
}

//N,4 3.4,1.3,2.51,3.24 -1 N,6 3.3,2.3,1.5,2.4,2.6,3.4 -1 A,0,4 -1 A,1,3.4 -1 N,3 2.1,2.3,1.6 -1 A,1,2.3 -1 A,2,3.5 -1
