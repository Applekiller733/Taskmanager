//
// Created by ANDREI on 27-Jun-24.
//

#ifndef TASKMANAGER_TASK_H
#define TASKMANAGER_TASK_H
#include <string>
#include <utility>

class Task {
private:
    std::string description;
    std::string status;
    int id = -1;
public:
    Task(std::string desc, std::string stat, int id) : description{std::move(desc)}, status{std::move(stat)}, id{id} {};
    [[nodiscard]] std::string getDescription() const {return this->description;};
    [[nodiscard]] std::string getStatus() const {return this->status;};
    [[nodiscard]] int getId() const {return this->id;};

    void setStatus(std::string newstat){this->status = std::move(newstat);};
    void setId(int newid){this->id = newid;};

};


#endif //TASKMANAGER_TASK_H
