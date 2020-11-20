#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>

#include "Goods.h"

using namespace std;

//constructor
Goods:: Goods(int quantity, int rate)
:quantity(quantity), rate(rate){}

//getters
int Goods:: getQuantity()
{
  return this->quantity;
}

//setters
void Goods:: setQuantity(int n)
{
  this->quantity = n;
}
