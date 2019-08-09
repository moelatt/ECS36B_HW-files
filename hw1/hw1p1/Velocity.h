//
// Velocity.h
//

#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
  private:
  int v;
  void set(int i);

  public:
  Velocity(void);
  int get(void);
  void accelerate(int dv);
  void print(void);
};
#endif

