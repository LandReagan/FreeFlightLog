#include <iostream>
#include <fstream>

#include "Console.h"

using namespace std;

int main()
{
    cout << "FreeFlightLog console v0.0" << endl;

    ofstream logCleaning("LOG.txt");
    logCleaning.close();



    try
    {
        unique_ptr<Console> console (new Console());
        console->main_loop();
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }

    cout << "FreeFlightLog exited safely" << endl;
    return 0;
}
