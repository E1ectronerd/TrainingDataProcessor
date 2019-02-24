cmake_minimum_required(VERSION 2.6)
project(trainingdataprocessor)

add_executable(trainingdataprocessor main.cpp CSVdata.cpp)

install(TARGETS trainingdataprocessor RUNTIME DESTINATION bin)
