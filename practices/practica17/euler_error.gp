# Configurar el tipo de gráfico
set title "euler_error con distintas h"
set xlabel "x"
set ylabel "z(x), z'(x) error"
set grid


set terminal png size 800,600
set output 'euler_error.png'
set key left

set xrange [0: 3]

# Graficar los puntos experimentales y la expresión teórica
plot "euler_error05.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.5)", \
	"euler_error05.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.5)" , \
	"euler_error01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.1)", \
	"euler_error01.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.1)" , \
	"euler_error005.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.05)", \
	"euler_error005.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.05)" , \
	"euler_error001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.01)", \
	"euler_error001.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.01)" , \
	"euler_error0005.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.005)", \
	"euler_error0005.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.005)" , \
	"euler_error0001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.001)", \
	"euler_error0001.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "z' (h = 0.001)" , \
