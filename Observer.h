//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>

class Subject; // forward declarotion 
using namespace std;

#include <vector>

/**
 * @brief defines the interface for objects that recieve notifications from subjects
 * 
 * Observer of the Observer pattern in the Gof Observer pattern
 * concrete observers inherit from this class and implement update()
 * 
 * 
 */

class Observer{
    private:
        /**
         * @brief Subjects currenlty being tracked by the observer
         * 
         * Observer uses pointers to maintain its relationship with the Subjects
         */
        vector<Subject*> subjects;
    public:
        /**
         * @brief Updates Observer to a subject notification.
         * 
         * concrete observers implement this operation
         * uses the pull form of the observer
         * 
         * @param subject the subject must remian valid while the update operation is being processed
         */
        virtual void update(Subject* subject) = 0;
        /**
         * @brief destroys the observer 
         * 
         */
        virtual ~Observer();
        /**
         * @brief Registers a subject for tracking by the observer.
         * 
         * ownership of subject remains with the component that manges its lifetime
         * 
         * @param sub Pointer to the subject that this observer should track
         */

        void trackSubject(Subject* sub);
        /**
         * @brief Stops tracking a subject
         * 
         * The Subject is removed from the observers collevction, but the subject 
         * itself is not deleted because the observer doesnt own it.
         * 
         * @param sub Pointer to the subject that sgould no longer be tracked.
         */
        void untrackSubject(Subject* sub);
};

#endif