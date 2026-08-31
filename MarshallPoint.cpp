#include <string>
#include <iostream>
#include <vector>
#include "MarshallPoint.h"
#include "Observer.h"
#include "MedicalTent.h"
#include "Subject.h"

using namespace std;

MarshallPoint::MarshallPoint(){
    sectorid = 0;
    
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
    case NoticeType::SHEDULE_CHANGE:
        close()
        break;
    case NoticeType::CAPICITY_ALERT:
        cout<< getCapacity() << endl;
    case NoticeType::MEDICAL_EMERGENCY:
        close();
    default:
        break;
    }

}

void MarshallPoint::open(){
    cout<<"The Marshallpoitn has been occupied"<<endl;

}

void MarshallPoint::close(){
    cout<<"The Marshall point has been disbanded"<<endl;

}

void MarshallPoint::reportStatus() const{
    if(open){
        cout << "A Marshall is at point: "<< sectorid << endl;
    }else{
        return "There are no marshalls in the post"<< endl;
    }
}

int MarshallPoint::getCapacity() const{
    return 5;
}


int MarshallPoint::getSectorID() const{
    return alertLevel;
}

void MarshallPoint::setSectorID(int id){
    sectorid = id;
}

MarshallPoint::~MarshallPoint(){
    
}

