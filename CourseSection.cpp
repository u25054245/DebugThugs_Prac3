#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "CourseSection.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

void CourseSection::add(MarathonEvent* child){
    children.pushback(child);
}

void CourseSection::remove(MarathonEvent* child){
    erase(children, child);
}

 MarathonEvent* CourseSection::release(MarathonEvent* child){

 }

void CourseSection::open(){
    for(size_t i = 0; i < children.size(); ++i){
        children[i].open();

    }

 }

void CourseSection::close(){
    for(size_t i = 0; i < children.size(); ++i){
        children[i].close();

    }

 }

void CourseSection::getCapacity(){
    int total = 0;
    for(size_t i = 0; i < children.size(); ++i){
        total += children[i].getCapacity();

    }
    return total;

 }

void CourseSection::reportStatus(){
    string total = "";
    for(size_t i = 0; i < children.size(); ++i){
        total += children[i].reportStatus();

    }
    return total;

 }

void CourseSection::update(Subject* subject){

 }

CourseSection::courseSection(){
    vector<MarathonEvent*> children;
 }

