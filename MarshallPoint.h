//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#ifndef MARSHALLPOINT_H
#define MARSHALLPOINT_H

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

/**
 * @brief Represents a Marshall Point in the marathon
 * 
 * MarshallPoint is a concrete leaf in the Gof Composite pattern 
 * beacuse it inherits from MarathonEvent but does not contain child MarathonEvent components
 * 
 * MarshallPoint aslo acts as an observer and can respond to notices issued by a Subject, such as weather alerts.
 * 
 * The Observer implemntation uses the pull approach. When the MarshallPoint recieves an update 
 * it can query the subject for the current notice usingg getCurrentNotice().
 */

class MarshallPoint : public MarathonEvent, public Observer{
    private:
        /**
         * @brief id for martials stationed
         */
        int sectorid;
        /**
         * @brief Indicates whether the Martial Point is operational
         * 
         * True indicates that the Martial point is currently operational
         * false indicates that it is closed or unavaailable
         */
        bool occupation;
        
    public:
        /**
         * @brief Responds toa  notification form a Subject
         * 
         * MartialPoint uses the pull form of the observer 
         * The SUbject is passed to this operation and the MartialPoint cna query 
         * it using the getCurrentNotice() to determine what notice was issued
         * 
         * @param subject pointer to the subject that genrated the notification
         */
        void update(Subject* subject);
        /**
         * @brief opens the Martial point
         */
        void open() override;
        /**
         * @brief closes th emartial Point
         */
        void close() override;
        /**
         * @brief Reports the current status of the Martial Point
         * 
         * the status includes information it is operational and the SectorId  
         */
        void reportStatus() const override;
        /**
         * @brief returns capacity of MartialPoint
         * @return the maximum capacity of the MartialPoint
         */
        int getCapacity() const override;
        /**
         * @brief returns the sector id
         * @return the current sectorID
         */
        int getSectorID() const;
        /**
         * @brief sets the sectorId
         * @param id is the new sector id 
         */
        void setSectorID(int id);
        
        /**
         * @brief destroys rhe masrshallPoint
         */
        ~MarshallPoint();
        /**
         * @brief constructs a medicalTent witht eh specified name
         * 
         * @param name the name assigned to the medic
         */
        MarshallPoint(string name);
};
#endif