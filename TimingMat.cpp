#include <string>
#include <iostream>
#include <vector>
#include "MarshallPoint.h"
#include "Observer.h"
#include "TimingMat.h"
#include "Subject.h"

using namespace std;

TimingMat::TimingMat(string name) : MarathonEvent(name) {
    recordedRunners = 0;
    operational = true;
}

void TimingMat::update(Subject* subject){
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
        close();
        break;
    case NoticeType::CAPICITY_ALERT:
        cout<< getCapacity() << endl;
        break;
    case NoticeType::MEDICAL_EMERGENCY:
        break;
    default:
        break;
    }
}



void TimingMat::open(){
    cout<<"The timingMat is recording runners"<<endl;
    operational = true;
}

void TimingMat::close(){
    cout<<"The Timingmat has stopped recording"<<endl;
    operational = false;
}

void TimingMat::reportStatus() const{
    if(operational){
        cout << "the timing mat has recorded : "<< recordedRunners <<" runners"<< endl;
    }else{
        cout << "The Timing Mat is not operational"<< endl;
    }
}

int TimingMat::getCapacity() const{
    return 5;
}


int TimingMat::getRecordedRunners() const{
    return recordedRunners;
}

void TimingMat::setRecordedRunners(int runners){
    recordedRunners = runners;
}

TimingMat::~TimingMat(){
    
}

