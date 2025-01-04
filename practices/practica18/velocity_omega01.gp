# Configurar el tipo de gráfico
set title " Velocidad para omega = 0.1"
set xlabel "t (s)"
set ylabel "v (m/s)"
set grid


set terminal png size 800,600
set output 'velocity_omega01.png'
set key left

set xrange [0: 100]

# Graficar los puntos experimentales y la expresión teórica
plot "rk4_data_01.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "x1'", \
	"rk4_data_01.txt" using 1:5 with linespoints pointtype 7 pointsize 0.5 title "x2'" , \
	"rk4_data_01.txt" using 1:7 with linespoints pointtype 7 pointsize 0.5 title "x3'", \

