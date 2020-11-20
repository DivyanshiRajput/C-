#ifndef PERISHABLE_H
#define PERISHABLE_H

#include "Goods.h"
#include "Perishable.h"

class Perishable: public Goods
{
public:
  int shelf_life;

public:
  Perishable (int quatity, int rate, int shelf_life);
};

#endif
