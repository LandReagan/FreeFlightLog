#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED

#include <string>

#include "Date.h"

class Flight
{
private:
    //REQUIRED DATA:
    Date date;

    //STATUS:
    bool defined;

public:
    Flight() : date(), defined(false) {}

    bool isDefined() const {return defined;}

    void getFlightInto(std::string&) const;
};

#endif // FLIGHT_H_INCLUDED
