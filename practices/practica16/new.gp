# Configurar el tipo de gráfico
set title "Error relativo derivada 2"
set xlabel "log_10 (h)"
set ylabel "log_10(error relativo)"
set grid


# salida 
set terminal png size 800,600
set output 'grafica2.png'


set xrange [-9: 1]
set yrange [-10:1]


# Graficar los puntos experimentales y la expresión teórica
plot "derivada2.txt" u 1:2 w lp title "centr2", \
	"derivada2.txt" u 1:3 w lp title "progr2" , \
	"derivada2.txt" u 1:4 w lp title "regr2"