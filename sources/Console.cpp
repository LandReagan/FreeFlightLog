#include "Console.h"

Console::Console()
{
    Log("Console constructor");
    try
    {
        manager = new Manager();
        buildMVC();
        checkFlightlogIntegrity();
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

Console::~Console()
{
    delete manager;
    Log("Console destructor");
}

void
Console::buildMVC()
{
    manager->buildMVC(this);
}

void
Console::main_loop()
{
    bool QUIT = false;
    while(!QUIT)
    {
        if (message.mess_type == UNDEF)
        {
            message.text = "What do you want to do? for help, type :help, to quit, type :q";
        }
        display();
        ask();
        manager->manage(message);
        if (message.mess_type == SYS_QUIT)
            QUIT = true;
    }
}

// PRIVATE___________________________________________________________

void
Console::display() const
{
    display(message.text);
}

void
Console::display(const std::string& s) const
{
    std::cout << s << std::endl;
}

void
Console::display(const char* p_char) const
{
    std::string s(p_char);
    display(s);
}

void
Console::display_prompt() const
{
    std::cout << '>';
}

void
Console::ask()
{
    display_prompt();
    std::string str;
    std::cin >> str;
    message.text = str;
}

void
Console::checkFlightlogIntegrity()
{
        manager->checkFlightlogData();
}
