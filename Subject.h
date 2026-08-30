#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"
using namespace std;

class Subject{
    protected:
        vector<Observer*> observers;
    public:
        virtual void attach(Observer* observer);
        virtual void detach(Observer* observer);
        virtual void notify();
        virtual ~Subject();

};

#endif