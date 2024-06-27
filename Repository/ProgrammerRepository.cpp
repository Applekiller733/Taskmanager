//
// Created by ANDREI on 27-Jun-24.
//

#include "ProgrammerRepository.h"

#include <utility>


ProgrammerRepository::ProgrammerRepository(std::string pfile) {
    this->programmersfile = std::move(pfile);

    std::ifstream pin(this->programmersfile);
    std::string delim = ",";
    std::string line;
    while(std::getline(pin, line)){
        std::string name = line.substr(0, line.find(delim));
        line.erase(0, line.find(delim) + delim.length());
        try {
            int id = std::stoi(line);
            Programmer prog(id, name);
            this->progs.push_back(prog);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid ID in progs file, line: " << line << "\n";
        }
    }
    pin.close();
}

Programmer *ProgrammerRepository::getProgrammerById(int id) {
    for (int i = 0; i < this->progs.size(); i++){
        if (progs[i].getId() == id)
            return &progs[i];
    }
    return nullptr;
}

Programmer *ProgrammerRepository::getProgrammerByName(std::string name) {
    for (int i = 0; i < this->progs.size(); i ++){
        if(progs[i].getName() == name)
            return &progs[i];
    }
    return nullptr;
}