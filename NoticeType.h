//u25420314 - Christian Khalid
//u25054245 - Nathan Spavins
//u25265718 - Jack Reid

#ifndef NOTICETYPE_H
#define NOTICETYPE_H

/**
 * @brief represents the differnet types of notices that can be issued throughout the EventControl System.
 * 
 * Noticetype is used in subjects to identify the type of event that has occurred and by the observers to determine
 * how they should react to the notification.
 */

enum class NoticeType{
    SHEDULE_CHANGE,
    RESUME,
    CAPICITY_ALERT,
    WEATHER_ALERT,
    MEDICAL_EMERGENCY,
    EVACUATE
};
#endif