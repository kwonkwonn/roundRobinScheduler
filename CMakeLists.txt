cmake_minimum_required(VERSION 3.26)
project(systemSoft C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(systemSoft
        doubleLink.c
        doubleLink.h
        Init.h
        main.c
        Scheduler.c
        Scheduler.h
        Thread.c
        Thread.h
        Init.c
        threadCon.c
        threadCon.h
        TestCase1.c
        TestCase2.c
        TestCase3.c)
