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
            children.erase(it);
            return;
        }
    }
}

 MarathonEvent* CourseSection::release(MarathonEvent* child){

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
    string total = name + ":";
    cout << total;
    for(size_t i = 0; i < children.size(); ++i){
        children[i]->reportStatus();

    }
    

 }

void CourseSection::update(Subject* subject){
    if(subject != nullptr){
        issueNotice(subject->getCurrentNotice());
    }
 }

CourseSection::CourseSection(){
    
}

