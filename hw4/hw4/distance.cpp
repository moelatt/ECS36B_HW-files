// Moe Ko Latt
// ID: 915866164
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

#include "Facility.h"
#include "Runway.h"
#include "Code.h"
#include "SiteNumber.h"

int main(int argc, char *argv[]){
    //Open Files
    std::ifstream RunwayFile, FacilityFile;

    RunwayFile.open("Runways.txt");
    FacilityFile.open("Facilities.txt");

    //Verify files are open
    if(!RunwayFile || !FacilityFile){
        std::cerr << "Error reading files" << std::endl;
    }

    // Fill out Runway
    std::vector<Runway* > Runways;
    std::string line;

    while(getline(RunwayFile,line)){
        Runways.push_back(new Runway(line));
    }

    // Fill out Facilitys
    std::vector<Facility* > Facilitys;

    while(getline(FacilityFile,line)){
        Facilitys.push_back(new Facility(line));
    }

    std::string code1, code2;
    code1 = argv[1];
    code2 = argv[2];

    if(code1.length()==3){
        code1+=" ";
    }
    if(code2.length()==3){
        code2+=" ";
    }

    //invalid codes
    if(code1.length()>4 || code2.length()>4){
        std::cout<< "Airport code must be at most 4 characters" << std::endl;
    } else {
        //Find Facility
        Code isOfCode1(code1); 
        Code isOfCode2(code2); 
        std::vector<Facility *>::iterator Code1_itter = std::find_if(Facilitys.begin(), Facilitys.end(), isOfCode1);
        std::vector<Facility *>::iterator Code2_itter = std::find_if(Facilitys.begin(), Facilitys.end(), isOfCode2);


        if (Code1_itter == Facilitys.end()) {
            std::cout << code1 << " not found" << std::endl;
        }else if(Code2_itter == Facilitys.end()){
            std::cout << code2 << " not found" << std::endl;
        } else {
            std::cout << code1 << " - " <<
                      code2 << " " << std::setprecision(0) << std::fixed <<
                      (*Code1_itter)->distance((*Code2_itter)->latitude(), (*Code2_itter)->longitude())
                      << " NM" << std::endl;

        }
    }
    RunwayFile.close();
    FacilityFile.close();
}