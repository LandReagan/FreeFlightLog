#ifndef DATAFIELD_H_INCLUDED
#define DATAFIELD_H_INCLUDED

#include <string>

// Abstract class for data to read/write into std::string database

class DataField
{
    std::string data;

public:
    DataField& operator<<(const std::string&);
};

#endif // DATAFIELD_H_INCLUDED
