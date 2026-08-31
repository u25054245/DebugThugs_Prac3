#ifndef SPECTATORSTANDS_H
#define SPECTATORSTANDS_H

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

class SpectatorStands : public MarathonEvent, public Observer{
    private:
        int capacity;
        
    public:
        void update(Subject* subject);
        void open() override;
        void close() override;
        void reportStatus() const override;
        int getCapacity() const override;
        int getCapacity() const;
        
        

        ~SpectatorStands();
        SpectatorStands();
};
#endif