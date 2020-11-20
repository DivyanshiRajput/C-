#ifndef STATIONARY_H
#define STATIONARY_H

#include "Stationary.h"
#include "Goods.h"

class Stationary: public Goods
{
public:
  int length;
  bool binding;

public:
  Stationary(int quantity, int rate, int length, bool b);
};

#endif
