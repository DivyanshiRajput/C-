#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
#include<vector>

#include "Ecosystem.h"

using namespace std;

int main()
{
  vector<Ecosystem> ecosystems ;
  vector<string> arr;
  string input, temp;
  getline(cin, input);
  stringstream ss(input);

  while (getline(ss,temp,' '))
  {
    //splitting with spaces
    arr.push_back(temp);
  }

  while(arr[0] != "-1")
  {
    vector<string> command;
    stringstream ss(arr[0]);
    while (getline(ss,temp,','))
    {
      //splitting with spaces
      command.push_back(temp);
    }
    //cout << command[0] << endl ;
    if(command[0] == "A")
    {
      int lad = stoi(command[1]);
      int lon = stoi(command[2]);
      int i = ecosystems.size();
      // Geolocation g(lad, lon);
      Ecosystem e(lad,lon, 0, 0, 0, 0, i+1);
      ecosystems.push_back(e);
    }

    else if(command[0] == "AA")
    {
      string animal = command[1];
      int num = stoi(command[2]);
      int index = stoi(command[3]);
      ecosystems[index].addAnimals(animal, num);
    }

    else if(command[0] == "DD")
    {
      string animal = command[1];
      int num = stoi(command[2]);
      int index = stoi(command[3]);
      ecosystems[index].deleteAnimals(animal, num);
    }

    else if(command[0] == "D")
    {
      int index = stoi(command[1]);
      ecosystems[index].deleteEcosystem();
    }

    else if(command[0] == "C")
    {
      int index = stoi(command[1]);
      int lad = stoi(command[2]);
      int lon = stoi(command[3]);
      int i = ecosystems.size();
      Ecosystem e = ecosystems[index];
      //Geolocation g(lad, lon);
      Ecosystem newe(lad, lon, e.getO(), e.getP(), e.getT(), e.getR(), i+1);
      ecosystems.push_back(newe);
    }
    //cout << arr[0] << endl;
    arr.erase(arr.begin());
  }
  for (int i = 0; i < ecosystems.size(); i++)
  {
    cout << i << "," <<  ecosystems[i] << " ";
  }
  int NP = 0;
  int NO = 0;
  int NR = 0;
  int NT = 0;
  for(int i = 0; i < ecosystems.size(); i++)
  {
        NP += ecosystems[i].getP() ;
        NO += ecosystems[i].getO() ;
        NR += ecosystems[i].getR() ;
        NT += ecosystems[i].getT() ;
  }

  cout << NO << "," << NP << "," << NR << "," << NT ;
  return 0;
}
