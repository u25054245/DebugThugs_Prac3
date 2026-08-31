#include "Subject.h"
#include "EventControl.h"
#include "Observer.h"

#include "MarathonEvent.h"

#include "WaterTable.h"
#include "MarshallPoint.h"
#include "MedicalTent.h"
#include "TimingMat.h"
#include "SpectatorStands.h"

#include "CourseSection.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    EventControl* ComeradesEvent = new EventControl();
    CourseSection* Comerades = new CourseSection("Comerades");

    ComeradesEvent->attach(Comerades);

    CourseSection* Hillcrest = new CourseSection("Hillcrest");
    Comerades->add(Hillcrest);
    Comerades->attach(Hillcrest);

    CourseSection* HillcrestHub = new CourseSection("Hillcrest Hub");
    Hillcrest->add(HillcrestHub);
    Hillcrest->attach(HillcrestHub);

    MedicalTent* HillcrestMedTent = new MedicalTent("Hillcrest Medical Tent");
    HillcrestHub->add(HillcrestMedTent);
    HillcrestHub->attach(HillcrestMedTent);

    WaterTable* HillcrestWaterTable = new WaterTable("Hillcrest Water Table");
    HillcrestHub->add(HillcrestWaterTable);
    HillcrestHub->attach(HillcrestWaterTable);

    MarshallPoint* HillcrestMarshalPoint = new MarshallPoint("Hillcrest Marshall");
    HillcrestMarshalPoint->setSectorID(3);
    HillcrestHub->add(HillcrestMarshalPoint);
    HillcrestHub->attach(HillcrestMarshalPoint);

    Comerades->open();
    cout << "Event has started\n" << endl;
    Comerades->reportStatus();
    cout << "\nTotal Capacity before notices: " << Comerades->getCapacity() << endl;

    cout << "\nNotice 1:" << endl;
    ComeradesEvent->issueNotice(NoticeType::WEATHER_ALERT);
    Comerades->reportStatus();

    cout << "\nNotice 2:" << endl;
    ComeradesEvent->issueNotice(NoticeType::CAPICITY_ALERT);
    Comerades->reportStatus();

    cout << "\nChange:" << endl;
    Hillcrest->detach(HillcrestHub);
    ComeradesEvent->issueNotice(NoticeType::RESUME);
    Comerades->reportStatus();
    Hillcrest->attach(HillcrestHub);

    cout << "\nReorganise:" << endl;
    HillcrestHub->detach(HillcrestMedTent);
    
    MarathonEvent* temp = HillcrestHub->release(HillcrestMedTent);

    if(temp != nullptr)
    {
        Comerades->add(temp);
        Comerades->attach(HillcrestMedTent);
        Comerades->reportStatus();
        cout << "Transferred leaf to another composite" << endl;
    }

    cout << "\nNotice 3 (ensuring the transfer worked):" << endl;
    ComeradesEvent->issueNotice(NoticeType::EVACUATE);
    Comerades->reportStatus();

    Comerades->close();
    cout << "\nEvent is finished:" << endl;

    delete ComeradesEvent;
    delete Comerades;

    return 0;
}