//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#ifndef WATERTABLE_H
#define WATERTABLE_H

#include <string>
#include <iostream>
#include <vector>
#include "MarathonEvent.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

/**
 * @brief Represents a water table event in the marathon
 * 
 * WaterTable is a concrete leaf in the Gof Composite pattern 
 * beacuse it inherits from MarathonEvent but does not contain child MarathonEvent components
 * 
 * WaterTable aslo acts as an observer and can respond to notices issued by a Subject, such as weather alerts.
 * 
 * The Observer implemntation uses the pull approach. When the WaterTable recieves an update 
 * it can query the sbject for the current notice usingg getCurrentNotice().
 */

class WaterTable : public MarathonEvent, public Observer{
    private:
        /**
         * @brief the number of cups currently available at the water Table
         */
        int remainingCups;
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
         * WaterTable uses the pull form of the observer 
         * The SUbject is passed to this operation and the WaterTable cna query 
         * it using the getCurrentNotice() to determine what notice was issued
         * 
         * @param subject pointer to the subject that genrated the notification
         */
        void update(Subject* subject);
        /**
         * @brief Opens the water table and makes it operational.
         */
        void open() override;
        /**
         * @brief opens the water table and makes it non-operationa;
         */
        void close() override;
        /**
         * @brief Reports the current status of the water table
         * 
         * the status includes information it is operational anf the remaining cups 
         */
        void reportStatus() const override;
        /**
         * @brief returns capacity of waterTbale
         * @return the maximum capacity of the water table
         */
        int getCapacity() const;
        /**
         * @brief Returns the number of cups remaining at the water table.
         * 
         * @return the current number of remaining cups
         */
        int getRemainingCups() const;
        /**
         * @brief refills the watertable
         * 
         * resores the available cups 
         */
        void refill();
        /**
         * @briefs destroys the watertable
         */

        ~WaterTable();
        /**
         * @brief constructs a watertable witht eh specified name
         * 
         * @param name the name assigned to the watertable
         */
        WaterTable(string name);
};
#endif

