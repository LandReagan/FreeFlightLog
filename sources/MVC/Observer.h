#ifndef OBSERVER_H_INCLUDED
#define OBSERVER_H_INCLUDED

class Observer
{
public:
    virtual void update() = 0;
    virtual void update(std::string&) = 0;
};

#endif // OBSERVER_H_INCLUDED
