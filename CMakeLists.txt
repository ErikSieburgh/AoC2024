# Root CMake file

cmake_minimum_required(VERSION 3.10)
project(AoC24)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an option to specify the day to build
option(SPECIFIC_DAY "Build only a specific day (01, 02, ... 25)" OFF)

# Add the functions directory
add_subdirectory(functions)

# If a specific day is requested, build only that day's subdirectory
if(SPECIFIC_DAY)
    string(FORMAT subdir "%02d" ${SPECIFIC_DAY})
    if(EXISTS "${CMAKE_SOURCE_DIR}/${subdir}/CMakeLists.txt")
        add_subdirectory(${subdir})
    else()
        message(FATAL_ERROR "Challenge ${subdir} does not exist.")
    endif()
else()
    # Add all challenges
    foreach(day RANGE 1 2)
        string(FORMAT subdir "%02d" ${day})
        if(EXISTS "${CMAKE_SOURCE_DIR}/${subdir}/CMakeLists.txt")
            add_subdirectory(${subdir})
        endif()
    endforeach()
endif()
