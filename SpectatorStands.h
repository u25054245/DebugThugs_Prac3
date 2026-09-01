//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#ifndef SPECTATORSTANDS_H
#define SPECTATORSTANDS_H

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;
/**
 * @brief Represents a spectator stand in the marathon
 * 
 * SpectatorStand is a concrete leaf in the Gof Composite pattern 
 * beacuse it inherits from MarathonEvent but does not contain child MarathonEvent components
 * 
 * SpectatorStand aslo acts as an observer and can respond to notices issued by a Subject, such as weather alerts.
 * 
 * The Observer implemntation uses the pull approach. When the SpectatorStand recieves an update 
 * it can query the subject for the current notice usingg getCurrentNotice().
 */

class SpectatorStands : public MarathonEvent, public Observer{
    private:
        /**
         * @brief the cpaacity of the spectator stands
         */
        int capacity;
        /**
         * @brief Indicates whether the water table is operational
         * 
         * True indicates that the water is currently operational
         * false indicates that it is closed or unavaailable
         */
        bool operational;
    public:
        /**
         * @brief Responds toa  notification form a Subject
         * 
         * Spectatorstands uses the pull form of the observer 
         * The SUbject is passed to this operation and the SpectatorStands cna query 
         * it using the getCurrentNotice() to determine what notice was issued
         * 
         * @param subject pointer to the subject that genrated the notification
         */
        void update(Subject* subject);
        /**
         * @brief opens the spectatorstands
         */
        
        void open() override;
        /**
         * @brief closes the SpectatorStands
         */
        void close() override;
        /**
         * @brief Reports the current status of the SPecattor STands
         * 
         * the status includes information it is operational and the Capacity  
         */
        void reportStatus() const override;
        /**
         * @brief returns capacity of SpectatorSTands
         * @return the maximum capacity of SPectatorSTands
         */
        int getCapacity() const override;
        
        
        /**
         * @brief destroys the SpectatorTSands
         */
        ~SpectatorStands();
        /**
         * @brief constructs a SpectatorSTands witht the specified name
         * 
         * @param name the name assigned to the medic
         */
        SpectatorStands(string name);
};
#endif