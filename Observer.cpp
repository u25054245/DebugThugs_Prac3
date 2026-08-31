//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#include "Observer.h"
#include "Subject.h"
#include <algorithm>
using namespace std;

void Observer::trackSubject(Subject* sub){
    if (sub && find(subjects.begin(), subjects.end(), sub) == subjects.end())
    {
        subjects.push_back(sub);
    }
    
}

void Observer::untrackSubject(Subject* sub){
    subjects.erase(remove(subjects.begin(), subjects.end(), sub), subjects.end());
}

Observer::~Observer(){
    vector<Subject*> det = subjects;
    for (size_t i = 0; i < det.size(); i++)
    {
        Subject* s = det[i];
        if(s != nullptr){
            s->detach(this);
        }
    }
    
}