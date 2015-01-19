#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

#include <iostream>
#include <fstream>

class Log
{
public:
    Log(const std::string& str)
    {
        std::ofstream stream("LOG.txt", std::ios::app);
        stream << str << '\n';
    }
};

#endif // LOG_H_INCLUDED
