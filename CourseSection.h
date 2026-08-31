#ifndef COURSESECTION_H
#define COURSESECTION_H

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer"

using namespace std;

class CourseSection : public MarathonEvent, public Observer{
    private:
        vector<MarathonEvent*> children;
    public:
        void add(MarathonEvent* child);
        void remove(MarathonEvent* child);
        MarathonEvent* release(MarathonEvent* child);
        virtual void open();
        virtual void close();
        virtual int getCapacity();
        virtual int getCapacity();
        void update(Subject* subject);
        courseSection();

    
};

#endif
