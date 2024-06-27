//
// Created by ANDREI on 27-Jun-24.
//

#ifndef TASKMANAGER_PROGRAMMERREPOSITORY_H
#define TASKMANAGER_PROGRAMMERREPOSITORY_H
#include <vector>
#include <string>
#include <exception>
#include "../Domain/Programmer.h"
#include <fstream>
#include <iostream>
#include "Observer.h"

class ProgrammerRepository : public Observable {
private:
    std::vector<Programmer> progs;
    std::string programmersfile;
public:
    ProgrammerRepository(std::string pfile);
    std::vector<Programmer> getProgrammers() const {return this->progs;};

    Programmer* getProgrammerById(int id);
    Programmer* getProgrammerByName(std::string name);
};


#endif //TASKMANAGER_PROGRAMMERREPOSITORY_H
