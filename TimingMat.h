#ifndef TIMINGMAT_H
#define TIMINGMAT_H

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

class TimingMat : public MarathonEvent, public Observer{
    private:
        int recordedRunners;
        bool operational;
        
    public:
        void update(Subject* subject);
        void open() override;
        void close() override;
        void reportStatus() const override;
        int getCapacity() const override;
        int getRecordedRunners() const;
        void setRecordedRunners(int runners);
        

        ~TimingMat();
        TimingMat(string name);
};
#endif