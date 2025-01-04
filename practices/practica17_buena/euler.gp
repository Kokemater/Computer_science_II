# Configurar el tipo de gráfico
set title "Euler con distintas h"
set xlabel "x"
set ylabel "z(x), z'(x)"
set grid


set terminal png size 800,600
set output 'grafico.png'
set key top left

set xrange [0: 3]


# Graficar los puntos experimentales y la expresión teórica
plot "euler05.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.5)", \
	"euler05.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.5)" , \
	"euler01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.1)", \
	"euler01.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.1)" , \
	"euler005.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.05)", \
	"euler005.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.05)" , \
	"euler001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.01)", \
	"euler001.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.01)" , \
	"euler0005.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.005)", \
	"euler0005.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.005)" , \
	"euler0001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.001)", \
	"euler0001.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.001)" , \
