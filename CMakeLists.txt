# Root CMake file

cmake_minimum_required(VERSION 3.10)
project(AoC24)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an option to specify the day to build
option(SPECIFIC_DAY "Build only a specific day (01, 02, ... 25)" OFF)

# # Add the functions directory
# add_subdirectory(functions)

# If a specific day is requested, build only that day's subdirectory
if(SPECIFIC_DAY)
    # Ensure SPECIFIC_DAY is always two digits
    if(SPECIFIC_DAY MATCHES "^[0-9]$")
        set(subdir "0${SPECIFIC_DAY}")
    elseif(SPECIFIC_DAY MATCHES "^[0-9][0-9]$")
        set(subdir "${SPECIFIC_DAY}")
    else()
        message(FATAL_ERROR "Invalid SPECIFIC_DAY value. Use a number between 1 and 25.")
    endif()

    if(EXISTS "${CMAKE_SOURCE_DIR}/${subdir}/CMakeLists.txt")
        add_subdirectory(${subdir})
    else()
        message(FATAL_ERROR "Challenge ${subdir} does not exist.")
    endif()
else()
    # Add all challenges
    foreach(day RANGE 1 2) # Update range as needed
        # Format the day to two digits
        if(day LESS 10)
            set(subdir "0${day}")
        else()
            set(subdir "${day}")
        endif()

        if(EXISTS "${CMAKE_SOURCE_DIR}/${subdir}/CMakeLists.txt")
            add_subdirectory(${subdir})
        endif()
    endforeach()
endif()
