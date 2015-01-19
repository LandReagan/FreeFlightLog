#include "Flight.h"

void
Flight::getFlightInto(std::string& str) const
{
    str.clear();
    date.getDateInto(str);
}
