//
// Created by ANDREI on 27-Jun-24.
//

#include "TaskRepository.h"
#include <fstream>
#include <iostream>
#include <utility>

TaskRepository::TaskRepository(std::string tfile) {
    this->tasksfile = std::move(tfile);

    std::string line;
    std::string delim = ",";
    std::ifstream tin(this->tasksfile);
    while(std::getline(tin, line)) {
        std::string desc = line.substr(0, line.find(delim));
        line.erase(0, line.find(delim) + delim.length());
        std::string status = line.substr(0, line.find(delim));
        line.erase(0, line.find(delim) + delim.length());
        std::string strid = line;
        try {
            int id;
            id = std::stoi(strid);
            Task t(desc, status, id);
            this->tasks.push_back(t);
        }
        catch (const std::invalid_argument& e){
            std::cout << "Error: Invalid ID in tasks file, line: " << line << "\n";
        }
    }
    tin.close();
}

void TaskRepository::removeTask(std::string description) {
    bool found = 0;
    auto it = this->tasks.begin();
    while ( it < this->tasks.end() && found == 0 ){
        if (it->getDescription() == description){
            found = 1;
            break;
        }
        it++;
    }
    this->tasks.erase(it);
}

void TaskRepository::addTask(std::string description, std::string status, int id) {
    Task t(description, status, id);
    this->tasks.push_back(t);
}

void TaskRepository::assignProgrammer(std::string description, int progid) {

    for (int i = 0; i < this->tasks.size(); i++){
        if (this->tasks[i].getDescription() == description && this->tasks[i].getStatus() == "open" /*and check if id valid*/){
            this->tasks[i].setStatus("in progress");
            this->tasks[i].setId(progid);
        }
        else if (this->tasks[i].getDescription() == description && this->tasks[i].getStatus() != "open"){
            throw std::runtime_error("Task already in progress");
        }
    }
}

void TaskRepository::finishTask(std::string description) {
    for (int i = 0; i < this->tasks.size(); i++){
        if (this->tasks[i].getDescription() == description && this->tasks[i].getStatus() == "in progress"){
            this->tasks[i].setStatus("done");
        }
    }
}

//void TaskRepository::sortByStatus() {
//    for (int i = 0; i < this->tasks.size()-1; i ++){
//        for(int j = i+1; j < this->tasks.size(); j++){
//            if ( this->tasks[i].getStatus() < this->tasks[j].getStatus() ){
//                std::swap(this->tasks[i], this->tasks[j]);
//            }
//        }
//    }
//}

