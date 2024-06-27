//
// Created by ANDREI on 27-Jun-24.
//

#ifndef TASKMANAGER_MANAGER_H
#define TASKMANAGER_MANAGER_H
#include "../Repository/ProgrammerRepository.h"
#include "../Repository/TaskRepository.h"
#include "../Repository/Models.h"
#include "ProgrammerGUI.h"
#include <QSortFilterProxyModel>


class Manager {
public:
    Manager(ProgrammerRepository* p, TaskRepository* t){

        auto model = new TaskTableModel(p, t);
        for (auto prog : p->getProgrammers()){
            auto gui = new ProgrammerGUI(p, t, model);
            gui->setWindowTitle(QString::fromStdString(prog.getName()));
            gui->show();
        }
    }
};


#endif //TASKMANAGER_MANAGER_H
