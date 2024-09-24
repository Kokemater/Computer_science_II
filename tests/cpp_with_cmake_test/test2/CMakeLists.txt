# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Define el nombre del proyecto
project(MiProyecto VERSION 1.0)

# Indica el estándar de C++ a utilizar
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Añade el ejecutable
add_executable(mi_proyecto 
main.cpp
func_1.cpp 
func_2.cpp)
