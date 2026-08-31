#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "WaterTable.h"
#include "Subject.h"

using namespace std;

WaterTable::WaterTable(){
    remaining cupe = 1000;
    open = false;

}

void WaterTable::update(Subject* subject){

}

void WaterTable::open(){
    operational = true;

}

void WaterTable::close(){
    operational = false;

}

void WaterTable::reportStatus() const{
    if(open){
        cout << "Water Table is OPEN. "<< remainingCups << " cups remaining."<<endl;
    }else{
        return remainingCups;
    }
}

int WaterTable::getCapacity() const{
    return 500;
}

int WaterTable::getRemainingCups(){
    return remainingCups;
}

void WaterTable::refill(){
    remainingCups = 1000;
}