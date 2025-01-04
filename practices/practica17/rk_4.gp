# Configurar el tipo de gráfico
set title "rk_4 con distintas h"
set xlabel "x"
set ylabel "z(x), z'(x)"
set grid


set terminal png size 800,600
set output 'rk_4.png'
set key top left

set xrange [0: 3]


# Graficar los puntos experimentales y la expresión teórica
plot "rk_405.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.5)", \
	"rk_405.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.5)" , \
	"rk_401.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.1)", \
	"rk_401.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.1)" , \
	"rk_4005.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.05)", \
	"rk_4005.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.05)" , \
	"rk_4001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.01)", \
	"rk_4001.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.01)" , \
	"rk_40005.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.005)", \
	"rk_40005.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.005)" , \
	"rk_40001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.001)", \
	"rk_40001.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.001)" , \
