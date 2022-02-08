cmake_minimum_required(VERSION 3.5)

project("jeux" LANGUAGES CXX)

set(SRC_DIR src/)


set(WARNING_FLAG
        -Wall
        -Wextra
        -Wpedantic
)

set(SRCS
        main.cpp
)
set(SRCS2
        main2.cpp
)
set(SRCS3
        main3.cpp
)
set(SRCS4
        main4.cpp
)
set(SRCS5
        main5.cpp
)

list(TRANSFORM SRCS PREPEND ${SRC_DIR})
list(TRANSFORM SRCS2 PREPEND ${SRC_DIR})
list(TRANSFORM SRCS3 PREPEND ${SRC_DIR})
list(TRANSFORM SRCS4 PREPEND ${SRC_DIR})
list(TRANSFORM SRCS5 PREPEND ${SRC_DIR})

add_executable(jeu1 ${SRCS})
add_executable(jeu2 ${SRCS2})
add_executable(jeu3 ${SRCS3})
add_executable(jeu4 ${SRCS4})
add_executable(jeu5 ${SRCS5})

target_include_directories( jeu1 PRIVATE
        ./include
)
target_include_directories( jeu2 PRIVATE
        ./include
)
target_include_directories( jeu3 PRIVATE
        ./include
)
target_include_directories( jeu4 PRIVATE
        ./include
)
target_include_directories( jeu5 PRIVATE
        ./include
)