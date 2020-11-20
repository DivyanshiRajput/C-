#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>

#include "Goods.h"
#include "Perishable.h"

using namespace std;

//constructor
Perishable:: Perishable(int quantity, int rate, int shelf_life)
: Goods(quantity, rate), shelf_life(shelf_life){}
