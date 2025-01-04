# Configurar el tipo de gráfico
set title "Error relativo derivada 3"
set xlabel "log_10 (h)"
set ylabel "log_10(error relativo)"
set grid


# salida 
set terminal png size 800,600
set output 'grafica3.png'


set xrange [-9: 1]
set yrange [-10:1]


# Graficar los puntos experimentales y la expresión teórica
plot "derivada3.txt" u 1:2 w lp title "centr2", \
	"derivada3.txt" u 1:3 w lp title "progr2" , \
	"derivada3.txt" u 1:4 w lp title "regr2"