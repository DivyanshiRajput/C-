#ifndef GEOLOCATION_H
#define GEOLOCATION_H

#include "Geolocation.h"

#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
#include<vector>//
using namespace std;

class Geolocation{
public:
  int x;
  int y;
  Geolocation(int x, int y);
  ~Geolocation();
  Geolocation(const Geolocation &GL);
};

#endif
