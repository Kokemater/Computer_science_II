# Configurar el tipo de gráfico
set title " Posición para omega = 10"
set xlabel "t (s)"
set ylabel "x (m)"
set grid


set terminal png size 800,600
set output 'posicion_omega10.png'
set key left

set xrange [0: 100]

plot "rk4_data_10.txt" using 1:6 with linespoints pointtype 7 pointsize 0.5 title "x3", \
	"rk4_data_10.txt" using 1:4 with linespoints pointtype 7 pointsize 0.5 title "x2" , \
	"rk4_data_10.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "x1", \
