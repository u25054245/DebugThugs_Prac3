//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "CourseSection.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

void CourseSection::add(MarathonEvent* child){
    children.push_back(child);
}

void CourseSection::remove(MarathonEvent* child){
    for(vector<MarathonEvent*>::iterator it = children.begin(); it != children.end(); ++it){
        if(*it == child){
            MarathonEvent* temp = *it;
            children.erase(it);
            delete temp;
            return;
        }
    }
}

 MarathonEvent* CourseSection::release(MarathonEvent* child){
    for(vector<MarathonEvent*>::iterator it = children.begin(); it != children.end(); ++it) {
        if(*it == child) {
            children.erase(it);
            return child;
        }
    }
    return nullptr;
 }

void CourseSection::open(){
    for(size_t i = 0; i < children.size(); ++i){
        children[i]->open();
    }
 }

void CourseSection::close(){
    for(size_t i = 0; i < children.size(); ++i){
        children[i]->close();
    }
}

int CourseSection::getCapacity() const{
    int total = 0;
    for(size_t i = 0; i < children.size(); ++i){
        total += children[i]->getCapacity();

    }
    return total;

 }

void CourseSection::reportStatus() const{
    string total = name + ":\n";
    cout << total;
    for(size_t i = 0; i < children.size(); ++i){
        children[i]->reportStatus();

    }
    

 }

void CourseSection::update(Subject* subject){
    if(subject == nullptr) return;
    
    issueNotice(subject->getCurrentNotice());
 }

CourseSection::CourseSection(string name) : MarathonEvent(name) {

}

CourseSection::~CourseSection() {
    for(size_t i = 0; i < children.size(); i++) {
        delete children[i];
    }

    children.clear();
}