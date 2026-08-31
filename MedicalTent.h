//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

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
        bool occupation;
        
    public:
        void update(Subject* subject);
        void open() override;
        void close() override;
        void reportStatus() const override;
        int getCapacity() const override;
        int getAlertLevel() const;
        void setAlertLevel(int level);
        

        ~MedicalTent();
        MedicalTent(string name);
};
#endif
