// Moe Ko Latt
// ID: 915866164
#include "Aircrew.h"
#include <iostream>
using namespace std;
Aircrew::Aircrew(std::string name_str):nm(name_str){}

	const double Aircrew::maxHours(void) const{
		int maxHours = 60;
		double availableHour = maxHours - hoursWorked;
		return availableHour;
	}
	const std::string Aircrew:: name(void) const{
		return nm;
	}
	void Aircrew::setFlights(int i){
	flightsTaken = i;
	}
 	void Aircrew:: setHours(double h){
        hoursWorked = h; 
 	}

 void Aircrew:: print(void) const{

    cout  << type()  << nm <<" has operated "<< flightsTaken << " flights for a total of ";
    cout << hoursWorked << " hours this week"<< endl;
    cout << "Available flights: " << maxFlights() << endl;
    cout << "Available hours: "<< maxHours() <<endl;	
 }
 void Aircrew::scheduleFlight(int f, double h)const{
 	cout << "Attempting to schedule for " << f <<" stop(s) " ;
    cout << h << " hours flight..." << endl;
    int totalFlight = flightsTaken + maxFlights();
    int numFlightTake = flightsTaken + f;
    double totalHour = hoursWorked + maxHours();
    double numHourTake = hoursWorked + h;
    if (totalFlight > numFlightTake && totalHour > numHourTake ){
    cout <<"This crew member can be scheduled"<<endl;
    
    }
    else{
    	cout << "This crew member should be replaced"<<endl;
    	
	}
}
	 Aircrew *Aircrew :: makeAircrew(char ch, string name_str){
	if (ch == 'P'){return new Pilot(name_str);}
	else if(ch == 'A'){return new Attendant(name_str);}
	else if (ch == 'T') {return new TaggedAttendant(name_str);}
	else{return 0;}

	}
	Aircrew::~Aircrew(){}
	
	Pilot::Pilot(std::string name_str):Aircrew(name_str){}
	const string Pilot::type(void)const{
		return "Pilot: ";
	}
	const int Pilot::maxFlights(void) const{
		int maxflights = 5;
		int availableFlights = maxflights - flightsTaken;
		return availableFlights;
	}
	
	Attendant::Attendant(std::string name_str):Aircrew(name_str){}
	const string Attendant::type(void)const{
		return "Attendant: ";
	}
	const int Attendant ::maxFlights(void) const{
		int maxflights = 8;
		int availableFlights = maxflights - flightsTaken;
		return availableFlights;
	}
	
	TaggedAttendant::TaggedAttendant(std::string name_str):Aircrew(name_str){}
	const string TaggedAttendant::type(void)const{
		return "TaggedAttendant: ";
	}
	const int TaggedAttendant::maxFlights(void) const{
		int maxflights = 8;
		int availableFlights = maxflights - flightsTaken;
		return availableFlights;
	}
	
    void TaggedAttendant::scheduleFlight(int f, double h) const{
	cout << "Attempting to schedule for " << f <<" stop(s) " ;
    cout << h << " hours flight..." << endl;
    int totalFlight = flightsTaken + maxFlights();
    int numFlightTake = flightsTaken + f;
    double totalHour = hoursWorked + maxHours();
    double numHourTake = hoursWorked + (h/2);
    if (totalFlight > numFlightTake && totalHour > numHourTake ){
    cout <<"This crew member can be scheduled"<<endl;
    
    }
    else{
    	cout << "This crew member should be replaced"<<endl;
    	
	}
	}

 




