#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>

#include <boost/date_time.hpp>

#include "../Utilities/Erreur.h"

using namespace boost::gregorian;

class Date
{
private:
    boost::gregorian::date d;
    bool defined;

public:
    Date() : d(1890, 10, 9), defined(false) {} // Clement Ader's first flight date...
    Date(std::string& s) : d(from_string(s)), defined(true) {}

    void getDateInto(std::string&) const;
};

#endif // DATE_H_INCLUDED
