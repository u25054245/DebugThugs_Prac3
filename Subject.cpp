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
        observer->unrackSubject(this);
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

Subject::~Subject(){

}