# Configurar el tipo de gráfico
set title "metodo diferencias finitas"
set xlabel "x"
set ylabel "u(x),"
set grid


set terminal png size 800,600
set output 'c.png'
set key top left
set logscale y

# Graficar los puntos experimentales y la expresión teórica
plot "c01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.01)", \
	"c001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.01)", \
	 "c0001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "z (h = 0.001)", \
