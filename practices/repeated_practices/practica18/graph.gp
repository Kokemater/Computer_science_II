

# Configurar el tipo de gráfico
set title " rk4 "
set xlabel "x"
set ylabel "u"
set grid


set terminal png size 800,600
set output 'graph4.png'
set key left


# Graficar los puntos experimentales y la expresión teórica
plot "rk4.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "1", \
	"rk4.txt" using 1:4 with linespoints pointtype 7 pointsize 0.5 title "2" , \
	"rk4.txt" using 1:6 with linespoints pointtype 7 pointsize 0.5 title "3", \
