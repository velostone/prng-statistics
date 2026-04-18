cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME prng-practrand)
project(${PROJECT_NAME})

find_package(Boost REQUIRED COMPONENTS random)

add_executable(${PROJECT_NAME} 
                    src/main.cpp
                    src/mcml_mcg59.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Boost::random
)