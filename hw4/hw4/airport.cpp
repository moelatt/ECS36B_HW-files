//// Moe Ko Latt
// ID: 915866164
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

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

    std::string code;
    code = argv[1];

    if(code.length()==3){
        code+=" ";
    }
    //invalid codes
    if(code.length()>4){
        std::cout<< "Airport code must be at most 4 characters" << std::endl;
    } else {
        //Find Facility
        Code isOfCode(code); //predicate
        std::vector<Facility *>::iterator Code_itter = std::find_if(Facilitys.begin(), Facilitys.end(), isOfCode);

        if (Code_itter == Facilitys.end()) {
            std::cout << code << " not found" << std::endl;
        } else {

            std::cout << (*Code_itter)->site_number() 
                      << std::setw(5)<< std::fixed <<(*Code_itter)->code() << " "
                      << (*Code_itter)->name() << " " << std::endl;

            //print the runways
            SiteNumber<Runway> isOfSite((*Code_itter)->site_number()); 
            std::vector<Runway *>::iterator Site_itter = std::partition(Runways.begin(), Runways.end(), isOfSite);

            for (std::vector<Runway *>::iterator it = --Site_itter; it != --Runways.begin(); it--) {

                std::cout << (*it)->site_number() << " "
                          << (*it)->name() << " "
                          <<(*it)->length()
                          << std::endl;
            }
        }
    }


    RunwayFile.close();
    FacilityFile.close();

}