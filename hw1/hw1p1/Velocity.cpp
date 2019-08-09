// Moe Ko Latt
// ID: 915866164
#include "Velocity.h"
#include <iostream>
using namespace std;

void Velocity::set(int i){
    v = i;
  }
  Velocity::Velocity(void){v = 0;}
  // (::) mean Binary Scope Resolution Operator
  int Velocity::get(void){
        return v;
  }
  void Velocity::accelerate(int dv){
    
    dv = v + dv;
      if(dv > 65){
        dv = 65;
      }
      else if (dv < -5){
      dv = -5;

    }
  
    set(dv);
  }
  void Velocity:: print(void){
    cout<<"Velocity: "<<v<<endl;
  }


  
  


