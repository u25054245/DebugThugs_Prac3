#ifndef MARSHALLPOINT_H
#define MARSHALLPOINT_H

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

class MarshallPoint : public MarathonEvent, public Observer{
    private:
        int sectorid;
        bool occupation;
        
    public:
        void update(Subject* subject);
        void open() override;
        void close() override;
        void reportStatus() const override;
        int getCapacity() const override;
        int getSectorID() const;
        void setSectorID(int id);
        

        ~MarshallPoint();
        MarshallPoint(string name);
};
#endif