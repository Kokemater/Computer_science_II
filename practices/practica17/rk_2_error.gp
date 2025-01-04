# Configurar el tipo de gráfico
set title "rk_2_error con distintas h"
set xlabel "x"
set ylabel "z(x), z'(x)"
set grid


set terminal png size 800,600
set output 'rk_2_error.png'
set key top left

set xrange [0: 3]

# Graficar los puntos experimentales y la expresión teórica
plot "rk_2_error05.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.5)", \
	"rk_2_error05.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.5)" , \
	"rk_2_error01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.1)", \
	"rk_2_error01.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.1)" , \
	"rk_2_error005.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.05)", \
	"rk_2_error005.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.05)" , \
	"rk_2_error001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.01)", \
	"rk_2_error001.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.01)" , \
	"rk_2_error0005.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.005)", \
	"rk_2_error0005.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.005)" , \
	"rk_2_error0001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.001)", \
	"rk_2_error0001.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.001)" , \
