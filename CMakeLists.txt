cmake_minimum_required(VERSION 3.15)
project(Audible)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH "/home/raulpavel/Qt/5.14.2/gcc_64/lib/cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Widgets REQUIRED)

add_executable(Audible main.cpp UI.cpp UI.h Database.cpp Database.h Book.cpp Book.h Controller.cpp Controller.h PersistenceEngine.cpp PersistenceEngine.h JSONparser.h mainwindow.cpp mainwindow.h clientwindow.cpp clientwindow.h)

target_link_libraries(Audible Qt5::Widgets)
