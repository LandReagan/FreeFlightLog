#include "Manager.h"

Manager::Manager()
{
    Log("Manager constructor");
    flightlogfile = new FlightlogFile();
}

Manager::~Manager()
{
    delete flightlogfile;
    Log("Manager destructor");
}

void
Manager::buildMVC(Observer* view)
{
    flightlogfile->addObserver(view);
    Log("MVC is built");
}

void
Manager::manage(Message& message)
{
    if (message.text[0] == ':')
        systemCommand(message);
    else
        /*entryCommand(message)*/;

    flightlogfile->notifyObservers(message.text);
}

void
Manager::checkFlightlogData()
{
    int calculatedKEY = flightlogfile->calculateKEY();
    int fileKEY = flightlogfile->getKEY();

    if (calculatedKEY != fileKEY)
        throw Erreur("File KEY non consistent", MEDIUM, FILE_ERROR);
}

void
Manager::systemCommand(Message& message)
{
    if (message.text == ":q")
        message.mess_type = SYS_QUIT;
    else if (message.text == ":help")
    {
        message.mess_type = SIMPLE_MESSAGE_TO_USER;
        message.text = "Available commands: :q to quit, :help for help, that's it!";
    }
}
