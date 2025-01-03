# Configurar el tipo de gráfico
set title "Posicion omega = 1"
set xlabel "tiempo"
set ylabel "Posiciones"
set grid


set terminal png size 800,600
set output 'pos_omega_1.png'
set key top left


plot "rk_4w1.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "x1", \
	"rk_4w1.txt" using 1:4 with linespoints pointtype 7 pointsize 0.5 title "x2" , \
	"rk_4w1.txt" using 1:6 with linespoints pointtype 7 pointsize 0.5 title "x3", \


# Configurar el tipo de gráfico
set title "Velocidad omega = 1"
set xlabel "tiempo"
set ylabel "Posiciones"
set grid


set terminal png size 800,600
set output 'vel_omega_1.png'
set key top left


plot "rk_4w1.txt" using 1:3 with linespoints pointtype 7 pointsize 0.5 title "x1", \
	"rk_4w1.txt" using 1:5 with linespoints pointtype 7 pointsize 0.5 title "x2" , \
	"rk_4w1.txt" using 1:7 with linespoints pointtype 7 pointsize 0.5 title "x3", \

