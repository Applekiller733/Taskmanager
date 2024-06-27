//
// Created by ANDREI on 27-Jun-24.
//

#ifndef TASKMANAGER_PROGRAMMERGUI_H
#define TASKMANAGER_PROGRAMMERGUI_H
#include <QTableView>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QSortFilterProxyModel>
#include "../Repository/Models.h"
#include "../Repository/TaskRepository.h"
#include "../Repository/ProgrammerRepository.h"

class ProgrammerGUI : public QWidget {
private:

    TaskRepository* trepo;
    ProgrammerRepository* prepo;

    QTableView* view;

    QLineEdit* descline;
    QLabel* desclabel;

    QPushButton* startbutton;
    QPushButton* addbutton;
    QPushButton* removebutton;
    QPushButton* donebutton;

    TaskTableModel* model;
    QSortFilterProxyModel* sort;

public:
    ProgrammerGUI(ProgrammerRepository* prepo, TaskRepository* t, TaskTableModel* model);
    void buildGUI();
    void onStartButtonPress();
    void onAddButtonPress();
    void onRemoveButtonPress();
    void onItemSelected();
    void onDoneButtonPress();
    void errWindow(std::string mssg){
        auto widget = new QWidget();
        auto layout = new QGridLayout();
        auto label = new QLabel{QString::fromStdString(mssg)};
        layout->addWidget(label);
        widget->setLayout(layout);
        widget->show();
    };
};


#endif //TASKMANAGER_PROGRAMMERGUI_H
