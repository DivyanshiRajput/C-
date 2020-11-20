#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>

#include "Goods.h"
#include "Stationary.h"

using namespace std;

//constructor
Stationary:: Stationary(int quantity, int rate, int length, bool b)
: Goods(quantity, rate), length(length), binding(b){}
