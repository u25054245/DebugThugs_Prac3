#ifndef MEDICALTENT_H
#define MEDICALTENT_H

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

class MedicalTent : public MarathonEvent, public Observer{
    private:
        int alertLevel;
        bool operational;
        int runnersServed;
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