#include <iostream>
#include <QApplication>
#include <QPushButton>
#include "Repository/TaskRepository.h"
#include "GUI/Manager.h"
#include <fstream>
#include <string>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
//    std::ifstream fin("../TaskRepository/tasktest.txt");
//    std::string line;
//    while(std::getline(fin, line))
//        std::cout << line << "\n";

    ProgrammerRepository prepo("../Repository/progtest.txt");
    TaskRepository trepo("../Repository/tasktest.txt");
    Manager man(&prepo, &trepo);

//    TaskRepository repo("../TaskRepository/progtest.txt", "../TaskRepository/tasktest.txt");
//    Repotests test(&repo);
//    test.repoTests();
    return app.exec();
}
