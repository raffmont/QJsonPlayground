cmake_minimum_required(VERSION 3.20)
project(QJsonPlayground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(QJsonPlayground main.cpp MainWindow.cpp MainWindow.hpp MainWindow.ui UIObject.cpp UIObject.hpp UIObject.ui UIArray.cpp UIArray.hpp UIArray.ui UIItem.cpp UIItem.hpp UIItem.ui)
target_link_libraries(QJsonPlayground
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

