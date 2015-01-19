#ifndef OBSERVABLE_H_INCLUDED
#define OBSERVABLE_H_INCLUDED

#include <vector>

#include "Observer.h"

class Observable
{
public:
    virtual void addObserver(Observer*) = 0;
    virtual void removeObserver(Observer*) = 0;
    virtual void notifyObservers() = 0;

protected:
    std::vector<Observer*> observers;
};

#endif // OBSERVABLE_H_INCLUDED
