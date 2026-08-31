//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

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
        virtual int getCapacity() const = 0;
        string getName();
        MarathonEvent();
        MarathonEvent(string n);
        virtual ~MarathonEvent();

};

#endif