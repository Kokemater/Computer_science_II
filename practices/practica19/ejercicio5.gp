# Configurar el tipo de gráfico
set title " Método del disparo para distintas h"
set xlabel "x"
set ylabel "u(x)"
set grid


set terminal png size 800,600
set output 'u_graph_ej5.png'
set key right

set xrange [0: 1]

# Graficar los puntos experimentales y la expresión teórica
plot "data15_h01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.1", \
	"data15_h0001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.001", \
	"data15_h001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title " h = 0.01" , \

# DERIVADA 
# Configurar el tipo de gráfico
set title " Método del disparo para distintas h"
set xlabel "x"
set ylabel "u'(x)"
set grid


set terminal png size 800,600
set output 'u_prime_graph_ej5.png'
set key right

set xrange [0: 1]

# Graficar los puntos experimentales y la expresión teórica
plot "data15_h01.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "h = 0.1", \
	"data15_h0001.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "h = 0.001", \
	"data15_h001.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "h = 0.01" , \


