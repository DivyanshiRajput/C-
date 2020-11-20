#ifndef GOODS_H
#define GOODS_H

#include "Goods.h"

class Goods
{
public:
  int quantity;
  int rate;

public:
  Goods(int quantity, int rate);
  int getQuantity();
  void setQuantity(int n);
};

#endif
