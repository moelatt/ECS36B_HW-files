// Moe Ko Latt
// ID: 915866164
#ifndef SITE_NUMBER_H
#define SITE_NUMBER_H
#include <string>
#include "Runway.h"
#include "Facility.h"

#include <iostream>

template <typename T>
class SiteNumber{
    public:
        SiteNumber<T>(std::string site) : site(site){}
        bool operator()(T* facility){ return facility->site_number() == site;}
    private:
        const std::string site;
};
#endif