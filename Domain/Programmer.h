//
// Created by ANDREI on 27-Jun-24.
//

#ifndef TASKMANAGER_PROGRAMMER_H
#define TASKMANAGER_PROGRAMMER_H
#include <string>

class Programmer {
private:
    int id;
    std::string name;
public:
    Programmer(int id, std::string name) : id{id}, name{name} {};
    const int getId(){return this->id;};
    const std::string getName(){return this->name;};
};


#endif //TASKMANAGER_PROGRAMMER_H
