#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "observer.h"


Child::Child()
{
    addObserver(new Dad());
    addObserver(new Mum());
    addObserver(new Dog());
}
Child::~Child()
{
}
void Child::addObserver(Observer* o)
{
    list<Observer*>::iterator it;
    for(it = m_obs.begin();it!= m_obs.end();++it){

        if(*it == o)
            break;
    }
    if(it == m_obs.end()){
        m_obs.push_back(o);
    }
}
void Child::rmObserver(Observer* o)
{
    list<Observer*>::iterator it;
    for(it = m_obs.begin();it!= m_obs.end();++it){

        if(*it == o)
            break;
    }
    if(it != m_obs.end()){
        m_obs.remove(*it);
        delete (*it);
    }
}
void Child::wakeupnotifyObserver()
{
    list<Observer*>::iterator it;
    WakeupEvent* pWakeupEvent;
    time_t rawtime;
    time(&rawtime);
    pWakeupEvent = new WakeupEvent(rawtime, "bed",this);
    for(it = m_obs.begin();it!= m_obs.end();++it){

        (*it)->ActionOnEvent(*pWakeupEvent);
    }
}