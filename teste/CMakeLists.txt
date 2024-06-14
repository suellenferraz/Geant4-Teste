cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(Simulation)

# Definir Geant4_DIR
set(Geant4_DIR /home/suellen/Downloads/geant4/lib/Geant4-10.7.3)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

add_executable(teste teste.cc ${sources} ${headers})
target_link_libraries(teste ${Geant4_LIBRARIES})

add_custom_target(Simulation DEPENDS teste)

