# Configurar el tipo de gráfico
set title "Resta"
set xlabel "x"
set ylabel "u(x),"
set grid


set terminal png size 800,600
set output 'Resta.png'
set key top left


# Graficar los puntos experimentales y la expresión teórica
plot "c01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.1)", \
	 "c001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.01)", \
	 "c0001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.001)", \
