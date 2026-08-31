#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "MedicalTent.h"
#include "Subject.h"

using namespace std;

MedicalTent::MedicalTent(){
    alertLevel = 0;
    
}

void MedicalTent::update(Subject* subject){
    if (subject == nullptr)
    {
        return;
    }

    switch (subject->getCurrentNotice())
    {
    case NoticeType::WEATHER_ALERT:
        setAlertLevel(3);
        break;
    case NoticeType::EVACUATE:
        close();
        break;
    case NoticeType::RESUME:
        open();
    case NoticeType::SHEDULE_CHANGE:
    case NoticeType::CAPICITY_ALERT:
        cout<< getCapacity() << endl;
    case NoticeType::MEDICAL_EMERGENCY:
        open();
        setAlertLevel(5);
        break;
    default:
        break;
    }
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
        cout << "Not Open"<< endl;
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

