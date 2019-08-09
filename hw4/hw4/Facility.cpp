// Moe Ko Latt
// ID: 915866164
#include "Facility.h"
#include "gcdistance.h"
#include <cstdlib>
#include <string>
using namespace std;

const int sec_in_deg = 3600;

Facility::Facility(std::string s): site_number_(s.substr(0,10)),
                                   type_(s.substr(11,12)),
                                   code_(s.substr(24,4)),
                                   name_(s.substr(130,49)),
                                   latitude_(convert_latitude(s.substr(535,12))),
                                   longitude_(convert_longitude(s.substr(562,12))) {

}

std::string Facility::site_number(void) const { return site_number_;}
std::string Facility::type(void) const { return type_;}
std::string Facility::code(void) const { return code_;}
std::string Facility::name(void) const { return name_;}
double Facility::latitude(void) const { return latitude_;}
double Facility::longitude(void) const { return longitude_;}

double Facility::distance(double lat, double lon) const {
    return gcdistance(lat, lon, latitude(), longitude());

}

double Facility::convert_latitude(std::string s) const {

    std::string tmp = s.substr(0,s.length()-2);
    double seconds = std::atof(tmp.c_str());
    double degrees = seconds/sec_in_deg;

    if(s[s.length()-1] == 'S'){
        degrees *= -1;
    }

    return degrees;
}

double Facility::convert_longitude(std::string s) const {

    std::string tmp = s.substr(0,s.length()-2);
    double seconds = std::atof(tmp.c_str());
    double degrees = seconds/sec_in_deg;

    if(s[s.length()-1] == 'W'){
        degrees *= -1;
    }

    return degrees;
}














