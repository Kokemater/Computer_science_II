# Configurar el tipo de gráfico
set title " Posición para omega = 10"
set xlabel "t (s)"
set ylabel "x (m)"
set grid


set terminal png size 800,600
set output 'posicion_maxima_omega10.png'
set key left

set xrange [0: 100]

# Graficar los puntos experimentales y la expresión teórica
plot "max_10_1.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "x1", \
	"max_10_2.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "x2" , \
	"max_10_3.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "x3", \
