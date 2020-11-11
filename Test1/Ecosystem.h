#ifndef ECOSYSTEM_H
#define ECOSYSTEM_H

#include "Ecosystem.h"
#include "Geolocation.h"

#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Ecosystem
{
private:
  bool is_live;
  Geolocation l;
  int index;
  int orangutans;
  int pandas;
  int tigers;
  int rhinos;

public:
  Ecosystem(int x, int y, int orangutans, int pandas, int tigers, int rhinos, int index);
  ~Ecosystem();
  friend ostream & operator << (ostream &out, const Ecosystem &ec);
  void addAnimals (string s, int n);
  void deleteAnimals (string s, int n);
  void deleteEcosystem();

  int getO();
  int getP();
  int getT();
  int getR();
};

#endif
