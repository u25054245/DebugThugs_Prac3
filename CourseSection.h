//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#ifndef COURSESECTION_H
#define COURSESECTION_H

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;
/**
 * @brief Represents the composite of the marathon course
 * 
 * is a branch of the composite tree and can contain multiple MarathonEvent components.
 * It implements the Composite pattern by allowing individual leaf events and nested courseSelections
 * to be treated uniformally through teh marathon Interface
 * 
 * CourseSelection also acts as n Observer and a Subject. it can recieve 
 * notifications from another Subject and can subsequentially notify its own Observers.
 * This allows event notifications to cascade through differnet leveles of the eventFlow structure
 * 
 * As a Composite, CourseSelevtion delgates operations such as open(), close(), reportStatus(), and getCapacity() to its child events.
 * 
 * The child pointers stored by CourseSeelction represent the event components belonging to course Selewction.
 * The ownerShip and lifetime of these objects must be managed consistently with the implementation of
 * add(), release(), and the destructor.
 */

class CourseSection : public MarathonEvent, public Observer, public Subject{
    private:
        /**
         * @brief the child event components contained in this section
         * 
         * Children are stored through the common MarathonEvent Interface allowing both leaf event components
         * and nested coursesections to be stored in the same Collection.
         */
        vector<MarathonEvent*> children;
    public:
        /**
         * @brief Adds an event componet to the course Section
         * 
         * The supplied Marathon pointer is stored as a chuld of this CourseSection
         * 
         * @param child Pointer tot he MarathonEvent component to add
         * 
         */
        void add(MarathonEvent* child);
        /**
         * @brief removes an event component from this course section
         * 
         * the child is removed from the collection
         * 
         * @param child Pointer tot he MarathonEvent component to remove
         */
        void remove(MarathonEvent* child);
        /**
         * @brief releases an event from this course section.
         * 
         * The child is removed from the CourseSection and its pointer is returned to the caller.
         * The operation is intended to support transfering resposibility for the event component 
         * 
         * @param child Pointer tot he MarathonEvent componentto release
         * @return Pointer to the released MarathonEvent, or nullptr if the child is not contained in this courseSection
         */
        MarathonEvent* release(MarathonEvent* child);
        /**
         * @brief opens all event components in this section
         * 
         * The operation is propagated to every child in the Composite
         */
        virtual void open() override;
        /**
         * @brief Closes all event components contained in this section
         * 
         * The opeartion is propagated to every in the Composite
         */
        virtual void close() override;
        /**
         * @brief reports the status of this section and its children 
         * 
         * The status operation is propagated to the child event componets in this courseSection
         */
        virtual void reportStatus() const override;
        /**
         * @brief Calculates the total capacity of this course section
         * 
         * The capacity is calculated combining the cpacities reported by all child MarathonEvent components 
         * 
         * @return the total capcity of the child event components
         */
        virtual int getCapacity() const override;
        /**
         * @brief responds to a notification from a Subject
         * 
         * CourseSection acts as an Observer and uses the pull form of the observer pattern.
         * It recieves a pointer to the subject and can query the Subject using getCurrentNotice()
         * to determine  which notice was issued
         * 
         * @param subject pointer to the Subject that generated the notification
         */
        void update(Subject* subject);
        /**
         * @brief constructs a courseSection witht eh specified name 
         * 
         * @param name The name assigned to the course section
         */
        CourseSection(string name);
        /**
         * @brief Destroys the CourseSection 
         * 
         * The destructor is resposible for handling the child event components 
         * acording to the ownership polocy of Composite.
         */
        ~CourseSection();
    
};

#endif

