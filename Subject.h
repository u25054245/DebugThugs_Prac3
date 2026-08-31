#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"
#include "NoticeType.h"
using namespace std;

class Subject{
    protected:
        vector<Observer*> observers;
        NoticeType currentNotice;
    public:
        virtual void attach(Observer* observer);
        virtual void detach(Observer* observer);
        virtual void notify();
        virtual void issueNotice(NoticeType notice);
        NoticeType getCurrentNotice() const;

        virtual ~Subject();
        Subject();

};

#endif