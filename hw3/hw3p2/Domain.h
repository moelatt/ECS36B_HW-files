//
// Domain.h
//
#ifndef DOMAIN_H
#define DOMAIN_H
#include "Shape.h"
#include<iostream>
#include<vector>

class Domain
{
  public:
  Domain(void);
  ~Domain(void);
  void addShape(const Shape* p);
  void draw(void);
  private:
  int sizex, sizey;
  std::vector<const Shape*> s;
};
#endif
