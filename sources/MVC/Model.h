#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include "../Utilities/Log.h"
#include "Observable.h"

class Model : public Observable
{
public:
    Model() {Log("Model constructor");}
    virtual ~Model() {Log("Model destructor");}

    void addObserver(Observer*);
    void removeObserver(Observer*);
    virtual void notifyObservers() = 0;

private:

};

#endif // MODEL_H_INCLUDED
