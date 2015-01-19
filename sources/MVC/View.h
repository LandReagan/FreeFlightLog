#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include <string>

#include "../Utilities/Log.h"
#include "Controller.h"

class View : public Observer
{
public:
    View() {Log("View Constructor");}
    virtual ~View() {Log("View Destructor");}

protected:
    Controller* controller;
};

#endif // VIEW_H_INCLUDED
