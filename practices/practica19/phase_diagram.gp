# DIAGRAMA DE FASES
# Configurar el tipo de gráfico
set title " Diagrama de fases para distintos gamma"
set xlabel "u(x)"
set ylabel "u'(x)"
set grid


set terminal png size 800,600
set output 'phase_diagram_graph.png'
set key right


# Graficar los puntos experimentales y la expresión teórica
plot "data05.txt" using 2:3 with linespoints pointtype 7 pointsize 0.5 title "gamma = 0.5", \
	"data1.txt" using 2:3 with linespoints pointtype 7 pointsize 0.5 title "gamma = 1" , \
	"data15.txt" using 2:3 with linespoints pointtype 7 pointsize 0.5 title "gamma = 1.5", \
