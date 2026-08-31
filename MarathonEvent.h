#ifndef MARATHONEVENT_H
#define MARATHONEVENT_H

#include <string>
#include <iostream>

using namespace std;

class MarathonEvent{
    protected:
        string name;
    public:
        virtual void open() = 0;
        virtual void close() = 0;
        virtual void reportStatus() const = 0;
        virtual void getCapacity() const = 0;
        string getName();
        MarathonEvent(string n);
        virtual ~MarathonEvent();

};

#endif