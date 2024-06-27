//
// Created by ANDREI on 27-Jun-24.
//

#ifndef TASKMANAGER_TASKREPOSITORY_H
#define TASKMANAGER_TASKREPOSITORY_H
#include <string>
#include <vector>
#include "../Domain/Task.h"
#include "Observer.h"

class TaskRepository : public Observable {
private:
    std::vector<Task> tasks;
    std::string tasksfile;
public:
    explicit TaskRepository(std::string tfile);
    void removeTask(std::string description);
    void addTask(std::string description, std::string status, int id);
    void assignProgrammer(std::string description, int progid);
    void finishTask(std::string description);

    std::vector<Task> getTasks() const { return this->tasks; };

};


#endif //TASKMANAGER_TASKREPOSITORY_H
