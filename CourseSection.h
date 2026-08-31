#ifndef COURSESECTION_H
#define COURSESECTION_H

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"

using namespace std;

class CourseSection : public MarathonEvent, public Observer{
    private:
        vector<MarathonEvent*> children;
    public:
        void add(MarathonEvent* child);
        void remove(MarathonEvent* child);
        MarathonEvent* release(MarathonEvent* child);
        virtual void open() override;
        virtual void close() override;
        virtual void getStatus() const override;
        virtual int getCapacity() const override;
        void update(Subject* subject);
        courseSection();

    
};

#endif

