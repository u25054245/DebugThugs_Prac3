//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>

class Subject; // forward declarotion 
using namespace std;

#include <vector>

class Observer{
    private:
        vector<Subject*> subjects;
    public:
        virtual void update(Subject* subject) = 0;
        virtual ~Observer();

        void trackSubject(Subject* sub);
        void untrackSubject(Subject* sub);
};

#endif