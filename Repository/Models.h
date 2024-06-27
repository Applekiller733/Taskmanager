//
// Created by ANDREI on 27-Jun-24.
//

#ifndef TASKMANAGER_MODELS_H
#define TASKMANAGER_MODELS_H
#include <QWidget>
#include <QAbstractTableModel>
#include "ProgrammerRepository.h"
#include "TaskRepository.h"
#include <string>


class TaskTableModel : public QAbstractTableModel{
private:
    ProgrammerRepository* prepo;
    TaskRepository* trepo;
public:
    TaskTableModel() = default;
    TaskTableModel(ProgrammerRepository* p, TaskRepository* t) : prepo{p}, trepo{t}{};

    int rowCount(const QModelIndex& parent) const override{
        return trepo->getTasks().size();
    };

    int columnCount(const QModelIndex& parent) const override{
        return 4;
    };

    QVariant data(const QModelIndex& ind, int role)const override{
        if (role == Qt::DisplayRole){
            switch(ind.column()){
                case 0:
                    return QString::fromStdString(trepo->getTasks()[ind.row()].getDescription());
                    break;
                case 1:
                    return QString::fromStdString(trepo->getTasks()[ind.row()].getStatus());
                    break;
                case 2:
                    return QString::number(trepo->getTasks()[ind.row()].getId());
                    break;
                case 3:
                    if (trepo->getTasks()[ind.row()].getId() != -1)
                        return  QString::fromStdString(prepo->getProgrammerById(trepo->getTasks()[ind.row()].getId())->getName());
                    else
                        return QString("");
                    break;
                default:
                    break;
            }
        }
        else
            return QVariant();
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override{
        if ( role != Qt::DisplayRole || orientation == Qt::Vertical)
            return QVariant();
        else{
            switch(section){
                case 0:
                    return "Description";
                    break;
                case 1:
                    return "Status";
                    break;
                case 2:
                    return "Programmer ID";
                    break;
                case 3:
                    return "Programmer Name";
                    break;
                default:
                    break;
            }
        }
    };

    bool setData(const QModelIndex& ind, const QVariant& value, int role) override{
        return QAbstractTableModel::setData(ind, value, role);
    }

    void addTask(const std::string description, const std::string status, const int progid){
        if (description.empty())
            throw std::runtime_error("Description empty");

        beginInsertRows(QModelIndex(), 0, 0);
        trepo->addTask(description, status, progid);
        endInsertRows();
        emit dataChanged(QModelIndex(), QModelIndex());
    };

    void assignProgrammer(std::string desc, int id){
        this->trepo->assignProgrammer(desc, id);
        emit dataChanged(QModelIndex(), QModelIndex());
    }

    void removeTask(std::string desc){
        this->trepo->removeTask(desc);
        emit dataChanged(QModelIndex(), QModelIndex());
    }

    void finishTask(std::string desc){
        this->trepo->finishTask(desc);
        emit dataChanged(QModelIndex(), QModelIndex());
    }

    ~TaskTableModel() {delete prepo; delete trepo;};
};



#endif //TASKMANAGER_MODELS_H
