#!/bin/bash

# Crea un directorio para la compilación si no existe
mkdir -p build

# Navega al directorio de compilación
cd build

# Ejecuta CMake para configurar el proyecto
cmake ..

# Compila el proyecto
make

# Ejecuta el programa
./mi_proyecto
