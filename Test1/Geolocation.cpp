#include<cstdlib>
#include<bits/stdc++.h>

#include "Geolocation.h"

#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

//constructor
Geolocation::Geolocation(int x, int y):x(x),y(y)
{
}

//destructor
Geolocation:: ~Geolocation(){}

//copy constructor
Geolocation:: Geolocation(const Geolocation &GL)
{
  this->x = GL.x;
  this->y = GL.y;
}
