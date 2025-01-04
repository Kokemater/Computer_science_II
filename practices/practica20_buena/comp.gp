# Configurar el tipo de gráfico
set title "resta diferencias finitas - disparo"
set xlabel "x"
set ylabel "u(x),"
set grid


set terminal png size 800,600
set output 'disparo_diferencia.png'
set key top left


# Graficar los puntos experimentales y la expresión teórica
plot "disparo_h_0.1.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z disparo (h = 0.1)", \
	"disparo_h_0.01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z disparo (h = 0.01)" , \
	"disparo_h_0.001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z disparo (h = 0.001)", \
	"diferencias_h_0.1.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.1)", \
	 "diferencias_h_0.01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.01)", \
	 "diferencias_h_0.001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.001)", \
