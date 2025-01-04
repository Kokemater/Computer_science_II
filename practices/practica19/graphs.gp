# Configurar el tipo de gráfico
set title " Método del disparo para gamma"
set xlabel "x"
set ylabel "u(x)"
set grid


set terminal png size 800,600
set output 'u_graph.png'
set key right

set xrange [0: 1]

# Graficar los puntos experimentales y la expresión teórica
plot "data05.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "gamma = 0.5", \
	"data1.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "gamma = 1" , \
	"data15.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "gamma = 1.5", \

# DERIVADA 
# Configurar el tipo de gráfico
set title " Método del disparo para gamma"
set xlabel "x"
set ylabel "u'(x)"
set grid


set terminal png size 800,600
set output 'u_prime_graph.png'
set key right

set xrange [0: 1]

# Graficar los puntos experimentales y la expresión teórica
plot "data05.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "gamma = 0.5", \
	"data1.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "gamma = 1" , \
	"data15.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "gamma = 1.5", \


