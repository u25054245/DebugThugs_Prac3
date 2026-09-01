//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#ifndef TIMINGMAT_H
#define TIMINGMAT_H

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;
/**
 * @brief Represents a TimingMat in the marathon
 * 
 * Timingmat is a concrete leaf in the Gof Composite pattern 
 * beacuse it inherits from MarathonEvent but does not contain child MarathonEvent components
 * 
 * TimingMat aslo acts as an observer and can respond to notices issued by a Subject, such as weather alerts.
 * 
 * The Observer implemntation uses the pull approach. When the TimingMat recieves an update 
 * it can query the subject for the current notice usingg getCurrentNotice().
 */

class TimingMat : public MarathonEvent, public Observer{
    private:
        /**
         * @brief the recorded runners by the timing mat
         */
        int recordedRunners;
        /**
         * @brief Indicates whether the Timing mat is operational
         * 
         * True indicates that the Timing mat is currently operational
         * false indicates that it is closed or unavaailable
         */
        bool operational;
        
    public:
    /**
         * @brief Responds toa  notification form a Subject
         * 
         * TimingMat uses the pull form of the observer 
         * The SUbject is passed to this operation and the TiminbvMat cna query 
         * it using the getCurrentNotice() to determine what notice was issued
         * 
         * @param subject pointer to the subject that genrated the notification
         */
        void update(Subject* subject);
        /**
         * @brief opens the timing mat
         */
        void open() override;
        /**
         * @brief closes the timing mat
         */
        void close() override;
        /**
         * @brief Reports the current status of the timingMat
         * 
         * the status includes information it is operational and the reocrdedRunners  
         */
        void reportStatus() const override;
        /**
         * @brief returns capacity of Timing Mat
         * @return the maximum capacity of the TimingMat
         */
        int getCapacity() const override;
        /**
         * @brief retyrns the recorded runners
         * @return the recorded runners are returned
         */
        int getRecordedRunners() const;
        /**
         * @brief sets the recorded runners
         * @param runners these are the amount of recorded runners set to this
         */
        void setRecordedRunners(int runners);
        
        /**
         *@brief destroys TimingMat
         */
        ~TimingMat();
        /**
         * @brief constructs a medicalTent witht eh specified name
         * 
         * @param name the name assigned to the medic
         */
        TimingMat(string name);
};
#endif