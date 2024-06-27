//
// Created by ANDREI on 27-Jun-24.
//

#ifndef TASKMANAGER_OBSERVER_H
#define TASKMANAGER_OBSERVER_H
#include <vector>

class Observer {
public:
    Observer();
    virtual void update() = 0;
};

class Observable {
private:
    std::vector<Observer *> obs;
public:

    void addObserver(Observer* o){
        obs.push_back(o);
    }

    void notify(){
        for (auto o: obs){
            o->update();
        }
    }
};


#endif //TASKMANAGER_OBSERVER_H
