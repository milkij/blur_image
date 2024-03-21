cmake_minimum_required(VERSION 3.23)
project(3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/usr/local")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(3 main.cpp photoeditor.cpp photoeditor.h photoeditor.ui)
target_link_libraries(3
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

