#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "MedicalTent.h"
#include "Subject.h"

using namespace std;

WaterTable::WaterTable(){
    alertLevel = 0;
    
}

void MedicalTent::update(Subject* subject){

}

void MedicalTent::open(){
    cout<<"The medical tent is open for injuries"<<endl;

}

void MedicalTent::close(){
    cout<<"The medical tent is closed, taking more people"<<endl;

}

void MedicalTent::reportStatus() const{
    if(open){
        cout << "Medical tent is on level: . "<< alertLevel << endl;
    }else{
        return "Not Open"<< endl;
    }
}

int MedicalTent::getCapacity() const{
    return 50;
}


int MedicalTent::getAlertLevel() const{
    return alertLevel;
}

void MedicalTent::setAlertLevel(int level){
    alertLevel = level;
}

MedicalTent::~MedicalTent(){
    
}

