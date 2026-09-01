//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#ifndef MARATHONEVENT_H
#define MARATHONEVENT_H

#include <string>
#include <iostream>

using namespace std;

/**
 * @brief Abstract base class representing an event component 
 * 
 * MarathonEvent defines the common interface shared by all marathon event components,
 * it acts as the component participant int he Gof composite pattern
 * 
 * All the Concrete leafs such as TimingMat and WaterTable, implement this interface
 * CourseSection also inherits from MarathonEvent
 */

class MarathonEvent{
    protected:
        /**
         * @brief the name identyfying marathon event.
         */
        string name;
    public:
        /**
         * @brief Opens/ activates the event component
         * 
         * Concrete subclasses define the specific behaviour that occurs when the event has opened
         */
        virtual void open() = 0;
        /**
         * @brief Closes or deactivates the event component 
         * 
         * Concrete subclasses define the specific behaviour that occurs when the event is closed
         */
        virtual void close() = 0;
        /**
         * @brief Reports the current status of the event component
         * 
         * concrete subclasses implement this operation about there current state
         */
        virtual void reportStatus() const = 0;
        /**
         * @brief returns the capacity of the event component 
         * 
         * for a leaf component, this represents the capacity of that individual event while in course section it can calculate the capacity of all the components that fall under it.
         * 
         * @return the capacity of the event component
         */
        virtual int getCapacity() const = 0;
        /**
         * @brief Returns the name of the event component
         * 
         * @return the name assigned to this marathon event
         * 
         */
        string getName();
        /**
         * @brief constructs a maratjon event with no specific name
         */
        MarathonEvent();
        /**
         * @brief constructs a MarathonEvent witht eh specified name
         * 
         * @param n the name to assign tot the marathon event.
         */
        MarathonEvent(string n);
        /**
         * @brief Destroys the MarathonEvent
         * 
         * The destructor is virtual so the derved event components can be safely destroyed through a MarathonEvent Pointer
         */
        virtual ~MarathonEvent();

};

#endif