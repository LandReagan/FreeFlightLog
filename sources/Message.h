#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#include <iostream>

enum MESS_TYPE {UNDEF = 0, SYS_QUIT, SIMPLE_MESSAGE_TO_USER, ENTER_FLIGHT};

struct Message
{
    MESS_TYPE mess_type;
    std::string text;

    Message() : mess_type(UNDEF), text("") {}

    friend std::istream& operator>>(std::istream& in, Message& message)
    {
        in >> message.text;
    }
};

#endif // MESSAGE_H_INCLUDED
