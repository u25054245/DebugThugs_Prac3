#include <string>
#include <iostream>
#include <vector>
#include "MarshallPoint.h"
#include "Observer.h"
#include "TimimgMat.h"
#include "Subject.h"

using namespace std;

TimingMat::TimingMat(){
    recordedRunners = 0;
    
}

void TimingMat::update(Subject* subject){
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
    default:
        break;
    }
}



void TimingMat::open(){
    cout<<"The timingMat is recording runners"<<endl;

}

void TimingMat::close(){
    cout<<"The Timingmat has stopped recording"<<endl;

}

void TimingMat::reportStatus() const{
    if(open){
        cout << "the timing mat has recorded : "<< recordedRunners <<" runners"<< endl;
    }else{
        return "The Timing Mat is not operational"<< endl;
    }
}

int TimingMat::getCapacity() const{
    return 5;
}


int TimingMat::getSectorID() const{
    return alertLevel;
}

void TimingMat::setSectorID(int id){
    sectorid = id;
}

TimingMat::~TimingMat(){
    
}

