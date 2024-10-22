# Establece el título y las etiquetas de los ejes
set title "Gráfica de datos x, y"
set xlabel "Eje X"
set ylabel "Eje Y"

# Establece el terminal de salida y el archivo de salida
set terminal png
set output 'grafica.png'

# Traza los datos del archivo
plot "results.txt" using 1:2 with linespoints title "Datos"

# Cierra el archivo de salida
set output

