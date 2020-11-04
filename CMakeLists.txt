cmake_minimum_required(VERSION 3.16)
project(oni_reader_clion)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "D:/Qt/Qt5.12.9/5.12.9/mingw73_32/lib/cmake")

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)

add_executable(oni_reader_clion main.cpp MainWindow.cpp MainWindow.h)

target_link_libraries(oni_reader_clion Qt5::Core)
target_link_libraries(oni_reader_clion Qt5::Widgets)
target_link_libraries(oni_reader_clion Qt5::Quick)