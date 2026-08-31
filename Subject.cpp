//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#include "Subject.h"
#include "Observer.h"
#include <vector>
#include <algorithm>
using namespace std;

void Subject::attach(Observer* observer){
    if(!observer){
        return;
    }
    
    if(find(observers.begin(), observers.end(),observer) == observers.end()){
        observers.push_back(observer);
        observer->trackSubject(this);
    }
}

void Subject::detach(Observer* observer){
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    if (observer)
    {
        observer->untrackSubject(this);
    }
    
}

void Subject::notify(){
    for(size_t i = 0; i < observers.size(); i++){
        Observer* observer = observers[i];
        if(observer != nullptr){
            observer->update(this);
        }
    }
}

void Subject::issueNotice(NoticeType notice){
    currentNotice = notice;
    notify();
}

NoticeType Subject::getCurrentNotice() const{
    return currentNotice;
}

Subject::~Subject(){
    vector<Observer*> temp = observers;

    for(size_t i = 0; i < temp.size(); i++) {
        if(temp[i] != nullptr) {
            temp[i]->untrackSubject(this);
        }
    }
}

Subject::Subject() {

}