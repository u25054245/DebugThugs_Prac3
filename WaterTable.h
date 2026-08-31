#ifndef WATERTABLE_H
#define WATERTABLE_H

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

class WaterTable : public MarathonEvent, public Observer{
    private:
        int remainingCups;
        bool operational;
       
    public:
        void update(Subject* subject);
        void open() override;
        void close() override;
        void reportStatus() const override;
        void getCapacity() const override;
        int getRemainingCups();
        void refill();

        ~WaterTable();
        WaterTable();
};
#endif

