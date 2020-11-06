cmake_minimum_required(VERSION 3.16)
project(oni_reader_clion)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.13.1/5.13.1/mingw73_32/lib/cmake")

# -----------------------------------------------------------------------------
# openNI
INCLUDE_DIRECTORIES(${OPEN_NI_BASE}/Include)

SET(LIBS ${LIBS} OpenNI2)

GET_FILENAME_COMPONENT(OPEN_NI_LIBDIR "${OPEN_NI_LIBDIR}" ABSOLUTE)

MESSAGE("OPEN_NI_BASE: ${OPEN_NI_BASE}")
set(OPEN_NI_LIBDIR "C:/Program Files/OpenNI2/Lib")
LINK_DIRECTORIES(${OPEN_NI_LIBDIR})
MESSAGE("OPEN_NI_LIBDIR: ${OPEN_NI_LIBDIR}")

# -----------------------------------------------------------------------------
# NITE
INCLUDE_DIRECTORIES(${NITE_BASE}/Include)
MESSAGE("NITE_BASE include: ${NITE_BASE}/Include")

IF(WIN32)
    FIND_LIBRARY(NITE_LIBRARY NAMES ${OPEN_LIBRARY_NAME} PATHS ${NITE_BASE}/lib)
ELSE()
    FIND_LIBRARY(NITE_LIBRARY NAMES ${OPEN_LIBRARY_NAME} PATHS ${NITE_BASE}/Redist)
ENDIF()

IF(NOT NITE_LIBRARY)
    # env is not set
    MESSAGE("OPEN_NI_BASE should be set, for example:")
    MESSAGE("> cmake -DOPEN_NI_BASE=/usr/lib/??? ..")
ENDIF()

SET(LIBS ${LIBS} ${NITE_LIBRARY})

# openNI lib
SET(OPEN_LIBRARY_NAME NiTE2)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)

add_executable(oni_reader_clion main.cpp MainWindow.cpp MainWindow.h)

target_link_libraries(oni_reader_clion Qt5::Core)
target_link_libraries(oni_reader_clion Qt5::Widgets)
target_link_libraries(oni_reader_clion Qt5::Quick)