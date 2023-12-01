cmake_minimum_required(VERSION 3.27)
project(RipperCurse)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(nlohmann_json REQUIRED)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(RipperCurse main.cpp
        Window.cpp
        Window.h
        JsonManip.cpp
        JsonManip.h
)

target_link_libraries(RipperCurse
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

# Specify the installation directory
set(CMAKE_INSTALL_PREFIX /path/to/installation/directory)

# Install the executable to the 'bin' directory
install(TARGETS RipperCurse DESTINATION bin)

# Install other files (e.g., headers, data files, etc.)
install(FILES Window.h JsonManip.h DESTINATION include)