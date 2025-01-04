# Configurar el tipo de gráfico
set title " Diagrama de fases para omega = 1"
set xlabel "t (s)"
set ylabel "x (m)"
set grid


set terminal png size 800,600
set output 'phase_diagram1.png'
set key left

set xrange [-2: 2]

# Graficar los puntos experimentales y la expresión teórica
plot "rk4_data.txt" using 2:3 with linespoints pointtype 7 pointsize 0.5 title "x1", \
	"rk4_data.txt" using 4:5 with linespoints pointtype 7 pointsize 0.5 title "x2" , \
	"rk4_data.txt" using 6:7 with linespoints pointtype 7 pointsize 0.5 title "x3", \

