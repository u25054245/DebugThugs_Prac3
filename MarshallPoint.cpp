#include <string>
#include <iostream>
#include <vector>
#include "MarshallPoint.h"
#include "Observer.h"
#include "MedicalTent.h"
#include "Subject.h"

using namespace std;

MarshallPoint::MarshallPoint(string name) : MarathonEvent(name) {
    sectorid = 0;
    occupation = true;
}

void MarshallPoint::update(Subject* subject){
    if (subject == nullptr)
    {
        return;
    }

    switch (subject->getCurrentNotice())
    {
    case NoticeType::WEATHER_ALERT:
    case NoticeType::EVACUATE:
        close();
        break;
    case NoticeType::RESUME:
        open();
        break;
    case NoticeType::SHEDULE_CHANGE:
        close();
        break;
    case NoticeType::CAPICITY_ALERT:
        cout << getCapacity() << endl;
        break;
    case NoticeType::MEDICAL_EMERGENCY:
        close();
        break;
    default:
        break;
    }

}

void MarshallPoint::open(){
    cout<<"The Marshallpoitn has been occupied"<<endl;
    occupation = true;
}

void MarshallPoint::close(){
    cout<<"The Marshall point has been disbanded"<<endl;
    occupation = false;
}

void MarshallPoint::reportStatus() const{
    if(occupation) {
        cout << "A Marshall is at point: "<< sectorid << endl;
    }else{
        cout << "There are no marshalls in the post" << endl;
    }
}

int MarshallPoint::getCapacity() const{
    return 5;
}


int MarshallPoint::getSectorID() const{
    return sectorid;
}

void MarshallPoint::setSectorID(int id){
    sectorid = id;
}

MarshallPoint::~MarshallPoint(){
    
}

