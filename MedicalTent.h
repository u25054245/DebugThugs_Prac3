//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#ifndef MEDICALTENT_H
#define MEDICALTENT_H

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;
/**
 * @brief Represents a medical tent in the marathon
 * 
 * MedicalTent is a concrete leaf in the Gof Composite pattern 
 * beacuse it inherits from MarathonEvent but does not contain child MarathonEvent components
 * 
 * MedicalTent aslo acts as an observer and can respond to notices issued by a Subject, such as weather alerts.
 * 
 * The Observer implemntation uses the pull approach. When the MedicalTent recieves an update 
 * it can query the subject for the current notice usingg getCurrentNotice().
 */

class MedicalTent : public MarathonEvent, public Observer{
    private:
    /**
     * @brief is the alert level of the medical Tent
     */
        int alertLevel;
        /**
         * @brief Indicates whether the Medical Tent is operational
         * 
         * True indicates that the Medical Tent is currently operational
         * false indicates that it is closed or unavaailable
         */
        bool occupation;
        
    public:
        /**
         * @brief Responds toa  notification form a Subject
         * 
         * MedicalTent uses the pull form of the observer 
         * The SUbject is passed to this operation and the MedicalTent cna query 
         * it using the getCurrentNotice() to determine what notice was issued
         * 
         * @param subject pointer to the subject that genrated the notification
         */
        void update(Subject* subject);
        /**
         * @brief opens the Medical tent and makes it non-operationa;
         */
        void open() override;
        /**
         * @brief closes the medical tent
         */
        void close() override;
         /**
         * @brief Reports the current status of the medical tent
         * 
         * the status includes information it is operational and the alert level  
         */
        void reportStatus() const override;
        /**
         * @brief returns capacity of medical tent
         * @return the maximum capacity of the MedicalTent
         */
        int getCapacity() const override;
        /**
         * @brief returns the current alertlevel of the medicaltent
         * 
         * @return the alert level
         */
        int getAlertLevel() const;
        /**
         * @brief sets the lert level of tyhe medical tent
         * 
         * @param level the level which alert level will be set too
         */
        void setAlertLevel(int level);
        
        /**
         * @brief destroys the medicalTent
         */
        ~MedicalTent();
        /**
         * @brief constructs a medicalTent witht eh specified name
         * 
         * @param name the name assigned to the medic
         */
        MedicalTent(string name);
};
#endif
