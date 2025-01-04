# Configurar el tipo de gráfico
set title "Disparo + rk4 con distintas h"
set xlabel "x"
set ylabel "u(x),"
set grid


set terminal png size 800,600
set output 'disparo.png'
set key top left


# Graficar los puntos experimentales y la expresión teórica
plot "disparo_h_0.1.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.1)", \
	"disparo_h_0.01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.01)" , \
	"disparo_h_0.001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.001)", \
