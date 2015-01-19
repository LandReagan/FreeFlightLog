#include "Date.h"

void
Date::getDateInto(std::string& str) const
{
    str.clear();
    int mday = (int) d.day();
    int mmonth = (int) d.month();
    int myear = (int) d.year();
    str += mday;
    str += "/";
    str += mmonth;
    str += "/";
    str += myear;
}
