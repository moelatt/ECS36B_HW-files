// Moe Ko Latt
// ID: 915866164
#include "Domain.h"
#include "Shape.h"
#include<iostream>
#include<vector>
#include <typeinfo>

Domain::Domain(void){
    sizex =  600;
    sizey = 500;
}

Domain::~Domain(void){
    s.clear();
}

void Domain::addShape(const Shape* p){
    s.push_back(p);
}

void Domain::draw(void){
    Rectangle* package = new Rectangle(Point(0,0), sizex, sizey);

    //Header for SVG
    std::cout << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>\n"
                 "<svg width=\"" << sizex + 100 << "\" height=\"" << sizey + 100 << "\"\n"
                 "xmlns=\"http://www.w3.org/2000/svg\">\n"
                 "<g transform=\"matrix(1,0,0,-1,50,550)\"\n"
                 "fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">" << std::endl;
    std::cout << "<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"" << sizex << "\" height=\"" << sizey << "\"/>" << std::endl;


    int does_not_fit = 0;
    int overlaps = 0;

    for(unsigned int i = 0; i < s.size(); i++){
        s[i]->draw();


        if(!(s[i]->fits_in(*package))){
            does_not_fit++;

        }
        for(unsigned int j = 0; j < s.size(); j++){
            if(s[j] != s[i]){
                if(s[i]->overlaps(*s[j])){
                    overlaps++;
                }
            }

        }

    }
    std::cout << "</g>\n"
                 "<g transform=\"matrix(1,0,0,1,50,590)\"\n"
                 " font-family=\"Arial\" font-size=\"32\">" << std::endl;

    if(does_not_fit > 0){
        std::cout << "<text x=\"0\" y=\"0\">does not fit</text>" << std::endl;
    } else if(overlaps > 0){
        std::cout << "<text x=\"0\" y=\"0\">overlap</text>" << std::endl;
    } else {
        std::cout << "<text x=\"0\" y=\"0\">ok</text>" << std::endl;
    }

    std::cout << "</g>\n"
                 "</svg>" << std::endl;


    delete package;

}