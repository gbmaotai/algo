#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <string>
#include <list>
using namespace std;

class ChildBase;

class WakeupEvent{
public:
     WakeupEvent(long timestamp,string Location,ChildBase* source){
        mtimestamp = timestamp;
        mLocation = Location;
        msource = source;
     };
    long mtimestamp;
    string mLocation;
    ChildBase* msource;
};
class Observer{
public:
    Observer() {};
    virtual ~Observer() {};
    virtual void ActionOnEvent(WakeupEvent event) =0;
};

class ChildBase{
public:
    ChildBase() {};
    virtual ~ChildBase() {};
    virtual void addObserver(Observer* o) = 0;
    virtual void rmObserver(Observer* o) = 0;
    virtual void wakeupnotifyObserver() = 0;
};

class Child : public ChildBase{
public:
    Child();
    virtual ~Child();
    virtual void addObserver(Observer* o); 
    virtual void rmObserver(Observer* o);
    virtual void wakeupnotifyObserver();
private:
    list<Observer*> m_obs;
};

class Dad : public Observer
{
    virtual void ActionOnEvent(WakeupEvent event){
        //printf("hug .... \n");
        printf("hug .... %s %s\n",ctime(&event.mtimestamp),event.mLocation.c_str());
    }
};
class Mum : public Observer
{
    virtual void ActionOnEvent(WakeupEvent event){
        printf("feed .... %s %s\n",ctime(&event.mtimestamp),event.mLocation.c_str());
    }
};
class Dog : public Observer
{
    virtual void ActionOnEvent(WakeupEvent event){
        printf("WangWang .... %s %s\n",ctime(&event.mtimestamp),event.mLocation.c_str());
    }
};
#endif
