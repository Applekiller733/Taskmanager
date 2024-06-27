//
// Created by ANDREI on 27-Jun-24.
//

#include "ProgrammerGUI.h"
#include <QSortFilterProxyModel>


ProgrammerGUI::ProgrammerGUI(ProgrammerRepository* p, TaskRepository* t, TaskTableModel* model) {
    this->prepo = p;
    this->trepo = t;
    this->model = model;

    this->sort = new QSortFilterProxyModel;
    sort->setSourceModel(model);
    sort->sort(1);
    this->buildGUI();
}

void ProgrammerGUI::buildGUI() {
    this->view = new QTableView;

    this->view->setModel(model);
    this->view->setMinimumSize(400, 100);

    this->desclabel = new QLabel{"Description:"};
    this->descline = new QLineEdit;


    this->addbutton = new QPushButton{"Add"};
    this->removebutton = new QPushButton{"Remove"};
    this->startbutton = new QPushButton{"Start"};
    this->donebutton = new QPushButton{ "Done" };

    auto layout = new QGridLayout;
    layout->addWidget(this->view, 0, 0, 10, 4);

    layout->addWidget(this->desclabel, 0, 5);
    layout->addWidget(this->descline, 0, 6);

    layout->addWidget(this->addbutton, 3, 5);
    layout->addWidget(this->removebutton, 4, 5);
    layout->addWidget(this->startbutton, 5, 5);
    layout->addWidget(this->donebutton, 6, 5);
    donebutton->hide();

    this->setLayout(layout);

    QObject::connect(addbutton, &QPushButton::pressed, this, &ProgrammerGUI::onAddButtonPress);
    QObject::connect(removebutton, &QPushButton::pressed, this, &ProgrammerGUI::onRemoveButtonPress);
    QObject::connect(startbutton, &QPushButton::pressed, this, &ProgrammerGUI::onStartButtonPress);
    QObject::connect(donebutton, &QPushButton::pressed, this, &ProgrammerGUI::onDoneButtonPress);
    QObject::connect(view, &QTableView::pressed, this, &ProgrammerGUI::onItemSelected);
}

void ProgrammerGUI::onAddButtonPress() {
    auto desc = this->descline->text().toStdString();

    try {
        this->model->addTask(desc, "open", -1);
    }
    catch (std::runtime_error &e){
        this->errWindow(e.what());
    }
//    this->trepo->addTask(desc, "open", -1);
}

void ProgrammerGUI::onRemoveButtonPress() {
    auto index = this->view->currentIndex();
    auto desc = this->view->model()->index(index.row(), 0).data().toString().toStdString();
//    std::cout << desc << "\n";
//    this->trepo->removeTask(desc);
    this->model->removeTask(desc);
}

void ProgrammerGUI::onStartButtonPress() {
    auto index = this->view->currentIndex();

    auto desc = this->view->model()->index(index.row(), 0).data().toString().toStdString();

    auto name = this->windowTitle().toStdString();
    auto id = this->prepo->getProgrammerByName(this->windowTitle().toStdString())->getId();
    try {
//        this->trepo->assignProgrammer(desc, id);
        this->model->assignProgrammer(desc, id);
    }
    catch (std::runtime_error &e){
        this->errWindow(e.what());
    }
}

void ProgrammerGUI::onDoneButtonPress() {
    auto index = this->view->currentIndex();

    auto desc = this->view->model()->index(index.row(), 0).data().toString().toStdString();
//    this->trepo->finishTask(desc);
    this->model->finishTask(desc);
    this->donebutton->hide();
}

void ProgrammerGUI::onItemSelected() {
    auto index = this->view->currentIndex();

    auto status = this->view->model()->index(index.row(), 1).data().toString().toStdString();
    auto tableid = this->view->model()->index(index.row(),2).data().toString().toInt();
    auto currid = this->prepo->getProgrammerByName(this->windowTitle().toStdString())->getId();
    if (status == "in progress" && tableid == currid){
        this->donebutton->show();
    }
}