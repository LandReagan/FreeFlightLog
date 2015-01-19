#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include "Utilities/Log.h"
#include "Utilities/Erreur.h"

#include "MVC/Controller.h"

#include "FlightlogFile.h"
#include "Flight/Flight.h"
#include "Message.h"

class Manager : public Controller
{
public:
    Manager();
    virtual ~Manager();

    void buildMVC(Observer*);
    void manage(Message& message);

    void checkFlightlogData();

    void enterFlight(){}

private:
    FlightlogFile* flightlogfile;
    Flight flight;

    void systemCommand(Message&);
    void entryCommand(std::string&);
};

#endif // MANAGER_H_INCLUDED
