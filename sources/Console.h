#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#include <iostream>
#include <string>

#include "Utilities/Log.h"
#include "Utilities/Erreur.h"

#include "MVC/View.h"
#include "Manager.h"
#include "Message.h"

class Console : public View
{
public:
    Console();
    virtual ~Console();

    void buildMVC();
    void main_loop();

    void update() {}
    void update(std::string& m) {message.text = m;}

    void enterFlight();

private:
    Manager* manager;
    Message message;

    void display() const;
    void display_prompt() const;
    void display(const std::string& s) const;
    void display(const char* p_char) const;

    void ask();


    void checkFlightlogIntegrity();
};

#endif // CONSOLE_H_INCLUDED
