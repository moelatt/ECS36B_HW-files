#include "Restaurant.h"
#include <iostream>
using namespace std;
Restaurant::Restaurant(int nLarge, int nMedium, int nSmall): size(nLarge+nMedium+nSmall){
    int i = 0;
    tableList = new Table*[size];

 	while(nLarge-- > 0 ){
 		tableList[i] = new Table(10);
 		i++;
 		cout << "Table " << i << " maximum occupancy 10" <<endl;

 	}
 	while(nMedium-- > 0){
 		tableList[i] = new Table(7);
 		i++;
 		cout << "Table " << i << " maximum occupancy 7" << endl;
 	}
 	while(nSmall-- > 0){
 		tableList[i] = new Table(5);
 		i++;
 		cout << "Table " << i << " maximum occupancy 5"<< endl;
 	}
 }
 void Restaurant::addGuests(int nGuests){
 	if (nGuests > 0){
 		for (int i = 0; i < size; i++){
 			if(tableList[i]-> addGuests(nGuests)){
 				cout << nGuests << " guests added to table "<<i + 1 << endl;
 				break;
 			}
 			if(i == size - 1){
 				cout << " could not accommodate "<< nGuests << " guests" << endl;
 			}
 		}
 	}
 	else{
 		throw invalid_argument("must be positive");
 	}


 }
 void Restaurant::printSummary(void){
 	cout << "Summary:"<< endl;
 	for(int i = 0; i < size; i++){
 		if(tableList[i]->currentOccupancy() != 0){
 			cout << "table " << i + 1 ;
 			cout << " " << tableList[i]->currentOccupancy();
 			cout << '/'<<tableList[i]->maxOccupancy()<<endl;
 		}
 	}

 }