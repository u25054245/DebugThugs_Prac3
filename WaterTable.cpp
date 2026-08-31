//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "WaterTable.h"
#include "Subject.h"
#include "CourseSection.h"
#include "NoticeType.h"

using namespace std;

WaterTable::WaterTable(string name) : MarathonEvent(name) {
    remainingCups = 1000;
}

void WaterTable::update(Subject* subject){
    if (subject == nullptr)
    {
        return;
    }

    switch (subject->getCurrentNotice())
    {
    case NoticeType::WEATHER_ALERT:
        break;
    case NoticeType::EVACUATE:
        close();
        break;
    case NoticeType::RESUME:
        open();
        break;
    case NoticeType::SHEDULE_CHANGE:
        refill();
        break;
    case NoticeType::CAPICITY_ALERT:
        break;
    case NoticeType::MEDICAL_EMERGENCY:
        break;
    default:
        break;
    }

    
}

void WaterTable::open(){
    cout<<"The water table has opened get drinks!"<<endl;
    operational = true;
}

void WaterTable::close(){
    cout<<"The water table has closed for no water available or not allowed to hand out."<<endl;
    operational = false;
}

void WaterTable::reportStatus() const{
    if(operational){
        cout << "Water Table is OPEN. "<< remainingCups << " cups remaining."<<endl;
    }else{
        cout << "The table is closed"<<endl;
    }
}

int WaterTable::getCapacity() const{
    return 500;
}

int WaterTable::getRemainingCups() const{
    return remainingCups;
}

void WaterTable::refill(){
    remainingCups = 1000;
}

WaterTable::~WaterTable() {

}