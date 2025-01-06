# Configurar el tipo de gráfico
set title "Error"
set xlabel "tau"
set ylabel "Error"
set grid

set terminal png size 800,600
set output 'graph4.png'
set key left


# Graficar los puntos experimentales y las curvas ajustadas
plot "error.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "diferencia_centrada_2", \
     "error.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "progresivas2", \
     "error.txt" using 1:4 with linespoints pointtype 7 pointsize 0.5 title "regresivas2", \
     "error.txt" using 1:5 with linespoints pointtype 7 pointsize 0.5 title "diferencia_centrada_3", \
     "error.txt" using 1:6 with linespoints pointtype 7 pointsize 0.5 title "progresivas3", \
     "error.txt" using 1:7 with linespoints pointtype 7 pointsize 0.5 title "regresivas3", \

