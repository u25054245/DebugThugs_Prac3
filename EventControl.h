#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include "Subject.h"
#include <string>

class EventControl : public Subject { //sing;e root subject that represents organistion and control center. gives main once clear object to call
    public:
        EventControl() {};
        ~EventControl() {};
};

#endif