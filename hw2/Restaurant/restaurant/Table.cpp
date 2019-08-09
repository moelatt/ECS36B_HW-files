// Moe Ko Latt
// ID: 915866164
#include "Table.h"

Table::Table(int n):maxGuests(n),numGuests(0){}
    int Table::maxOccupancy(void){
    	return maxGuests;
    }
    int Table::currentOccupancy(void){
    	return numGuests;
    }
    bool Table::addGuests(int n){
    	if (n + numGuests <= maxGuests){
    		numGuests += n;
    		return true;
    	}
    	return false;
    }