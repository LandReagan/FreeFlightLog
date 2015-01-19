#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "Observer.h"
#include "Model.h"

class Controller
{
public:
    Controller() {Log("Controller constructor");}
    virtual ~Controller() {Log("Controller destructor");}

    //void blink(Observer* view) const {model->blink(view);}

private:
    Model* model;
};

#endif // CONTROLLER_H_INCLUDED
