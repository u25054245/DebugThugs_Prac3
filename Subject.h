//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"
#include "NoticeType.h"
using namespace std;

/**
 * @brief Provides the subject interface for the observer pattern.
 * 
 * Subject maintains a collection of observers and notifi4\es them whne its current notice changes
 * 
 * This class is the subject participant in the gof observer pattern.
 * Concrete subjects can inherit from this class and use issueNotice()
 * to publish notices to their registered observers.
 * 
 * Subject does not create or delete the observer objects. The lifetime of 
 * each observer must therefore be managed by the component that created it and an observer 
 * should be detacthed before it is destroyed
 */

class Subject{
    protected:
        /**
         * @brief Collection of registered Observers.
         * 
         * Subject uses them to send notifications.
         */
        vector<Observer*> observers;
        /**
         * @brief the most recently used notice
         * 
         * observers using the pull form can retrieve this value through getCurrentNotice().
         * 
         */
        NoticeType currentNotice;
    public:
        /**
         * @brief Registers an Observer with this Subject.
         * 
         * @param observer Pointer tot he Observer that should recieve notifications from this Subject.
         */
        virtual void attach(Observer* observer);
        /**
         * @brief removes an observer from this subject
         * 
         * removing an observer prevents it from recieving future notifications
         * The observe ritself is not deleted because the subject does not own it
         * 
         * @param observer pointer to the observe rto remove
         */
        virtual void detach(Observer* observer);
        /**
         * @brief Notifies all registered observers that the subject has changed.
         * 
         * The pull implementation, the subject passes itself 
         * to each observers's update() operation. Then each observer can query for the current notice using getCurrentNotice().
         * 
         */
        virtual void notify();
        /**
         * @brief issues a notice and makes it the current notice.
         * 
         * the notice is stored by th subject and can be retrived by Observers using
         * getCurrentNotice()
         * 
         * @param notice the new notice to issue
         */
        virtual void issueNotice(NoticeType notice);
        /**
         * @brief retrieves the subjects current notice
         * 
         * This operation supports the pull form.
         * An Observer can call this method after recieving a notification
         * 
         * @return the most recently issued NoticeType
         */
        NoticeType getCurrentNotice() const;
        /**
         * @brief Destroys the subject
         * 
         * The Subject does not own the registered observers therefor doesnt delete them
         * 
         */
        virtual ~Subject();
        /**
         * @brief constructor creates the object
         *
         *  Subject doesnt own the registeres observers
         */
        Subject();

};

#endif