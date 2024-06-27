cmake_minimum_required(VERSION 3.27)
project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.7.1/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(TaskManager main.cpp
        Domain/Programmer.h
        Domain/Task.h
        Repository/TaskRepository.cpp
        Repository/TaskRepository.h
        Repository/Observer.h
        Repository/ProgrammerRepository.cpp
        Repository/ProgrammerRepository.h
        GUI/ProgrammerGUI.cpp
        GUI/ProgrammerGUI.h
        GUI/Manager.h
        Repository/Models.h)

target_link_libraries(TaskManager
        Qt::Core
        Qt::Gui
        Qt::Widgets
)