#!/bin/bash

# Comando de prueba de Bash con condición

# Definir el nombre del archivo o directorio a comprobar
archivo_o_directorio="$1"

# Verificar si el archivo o directorio existe
if [ -e "$archivo_o_directorio" ]; then
    echo "El archivo o directorio '$archivo_o_directorio' existe."
else
    echo "El archivo o directorio '$archivo_o_directorio' no existe."
fi

# Verificar si es un archivo regular
if [ -f "$archivo_o_directorio" ]; then
    echo "'$archivo_o_directorio' es un archivo regular."
else
    echo "'$archivo_o_directorio' no es un archivo regular."
fi

# Verificar si es un directorio
if [ -d "$archivo_o_directorio" ]; then
    echo "'$archivo_o_directorio' es un directorio."
else
    echo "'$archivo_o_directorio' no es un directorio."
fi

# Verificar si el usuario tiene permisos de escritura en el archivo o directorio
if [ -w "$archivo_o_directorio" ]; then
    echo "Tienes permisos de escritura en '$archivo_o_directorio'."
else
    echo "No tienes permisos de escritura en '$archivo_o_directorio'."
fi

# Finalizar el script
echo "Fin del script de prueba."

echo "Archivos en el directorio actual:"
ls -l

# Realizar un bucle para contar del 1 al 5
echo "Contando del 1 al 5:"
for i in {1..5}
do
    echo "Número: $i"
done