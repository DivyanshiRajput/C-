#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>

#include "Ecosystem.h"

#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

//constructor
Ecosystem::Ecosystem(int x, int y, int orangutans, int pandas, int tigers, int rhinos, int index):
l(x,y), orangutans(orangutans), pandas(pandas), tigers(tigers), rhinos(rhinos), index(index), is_live(true)
{

}

//destructor
Ecosystem:: ~Ecosystem(){}

void Ecosystem:: addAnimals(string s, int n)
{
  if(this->is_live == true)
  {
    if (s.compare("T"))
    {
      this->tigers += n;
    }
    else if (s.compare("O"))
    {
      this->orangutans += n;
    }
    else if (s.compare("R"))
    {
      this->rhinos += n;
    }
    else if (s.compare("P"))
    {
      this->pandas += n;
    }
  }
}

//friend functions
ostream & operator << (ostream &out, const Ecosystem &ec)
{
  out << ec.l.x ;
  out << "," ;
  out << ec.l.y ;
  out << "," ;


  out << ec.is_live << "," ;

  out << ec.orangutans << "," ;
  out << ec.pandas << "," ;
  out << ec.rhinos << "," ;
  out << ec.tigers ;

  return out ;
}

void Ecosystem:: deleteAnimals(string s, int n)
{
  if(this->is_live == true)
  {
    if (s.compare("T"))
    {
      if (this->tigers >= n)
        this->tigers -= n;
    }
    else if (s.compare("O"))
    {
      if (this->orangutans >= n)
        this->orangutans -= n;
    }
    else if (s.compare("R"))
    {
      if (this->rhinos >= n)
        this->rhinos -= n;
    }
    else if (s.compare("P"))
    {
      if (this->pandas >= n)
        this->pandas -= n;
    }
  }
}

void Ecosystem:: deleteEcosystem()
{
  this->is_live = false;
  this->orangutans = 0;
  this->pandas = 0;
  this->tigers = 0;
  this->rhinos = 0;
}

//getters
int Ecosystem:: getO()
{
  return this->orangutans;
}

int Ecosystem:: getP()
{
  return this->pandas;
}

int Ecosystem:: getT()
{
  return this->tigers;
}

int Ecosystem:: getR()
{
  return this->rhinos;
}
