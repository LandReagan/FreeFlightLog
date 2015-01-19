#include "Model.h"

void
Model::addObserver(Observer* obs)
{
    observers.push_back(obs);
}

void
Model::removeObserver(Observer* obs)
{
    std::vector<Observer*> temp;
    for (std::size_t i = 0; i < observers.size(); ++i)
    {
        if (observers[i] != obs)
        {
            temp.push_back(observers[i]);
        }
    }
    observers = temp;
}
