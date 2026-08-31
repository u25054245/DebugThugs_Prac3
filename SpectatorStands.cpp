#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "SpectatorStands.h"
#include "Subject.h"

using namespace std;

SpectatorStands::SpectatorStands(){
    capacity = 500;
    
}

void SpectatorStands::update(Subject* subject){
    if (subject == nullptr)
    {
        return;
    }

    switch (subject->getCurrentNotice())
    {
    case NoticeType::WEATHER_ALERT:
        close();
        break;
    case NoticeType::EVACUATE:
        close();
        break;
    case NoticeType::RESUME:
        open();
    case NoticeType::SHEDULE_CHANGE:
    case NoticeType::CAPICITY_ALERT:
        getCapacity();
    case NoticeType::MEDICAL_EMERGENCY:
        break;
    default:
        break;
    }
}

void SpectatorStands::open(){
    cout<<"The Spectator stands are open come watch"<<endl;

}

void SpectatorStands::close(){
    cout<<"The specatator stands are closed"<<endl;

}

void SpectatorStands::reportStatus() const{
    if(open){
        cout << "The spectator stands capacity is: "<< capacity << endl;
    }else{
        cout<< "Not Open"<< endl;
    }
}

int SpectatorStands::getCapacity() const{
    return capacity;
}


SpectatorStands::~SpectatorStands(){
    
}

