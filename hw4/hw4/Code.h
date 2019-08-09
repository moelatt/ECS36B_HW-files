// Moe Ko Latt
// ID: 915866164
#ifndef CODE_H
#define CODE_H

#include "Facility.h"
#include <string>
#include <iostream>

class Code{
    public:
        Code(std::string code) : code_(code){}
        bool operator()(Facility* facility){ return facility->code() == code_;}
    private:
        const std::string code_;

};
#endif