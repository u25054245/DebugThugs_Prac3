#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "WaterTable.h"
#include "Subject.h"

using namespace std;

WaterTable::WaterTable(){
    remainingCups = 1000;
    

}

void WaterTable::update(Subject* subject){

}

void WaterTable::open(){
    cout<<"The water table has opened get drinks!!"<<endl;

}

void WaterTable::close(){
    cout<<"The water table has closed for no water available or not allowed to hand out."<<endl;

}

void WaterTable::reportStatus() const{
    if(open){
        cout << "Water Table is OPEN. "<< remainingCups << " cups remaining."<<endl;
    }else{
        cout << "The table is closed"<<endl;
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
