cmake_minimum_required(VERSION 3.7)
project(src)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        VWahl/database.cpp
        VWahl/database.h
        VWahl/databasedialog.cpp
        VWahl/databaseDialog.h
        VWahl/databasedialog.h
        VWahl/kandidat.cpp
        VWahl/kandidat.h
        VWahl/logger.cpp
        VWahl/logger.h
        VWahl/main.cpp
        VWahl/main.h
        VWahl/mainwindow.cpp
        VWahl/mainwindow.h
        VWahl/partei.cpp
        VWahl/partei.h
        VWahl/plots.cpp
        VWahl/plots.h
        VWahl/plottest.cpp
        VWahl/plottest.h
        VWahl/presentationwindow.cpp
        VWahl/presentationwindow.h
        VWahl/qcustomplot.cpp
        VWahl/qcustomplot.h
        VWahl/record.cpp
        VWahl/record.h
        VWahl/settingswindow.cpp
        VWahl/settingswindow.h
        VWahl/wahllokal.cpp
        VWahl/wahllokal.h)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

add_executable(src ${SOURCE_FILES})

qt5_use_modules(src Sql Gui Widgets)
