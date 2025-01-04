# Configurar el tipo de gráfico
set title "Error según el método"
set xlabel "log_10 (h)"
set ylabel "log_10(error)"
set grid


# Elegir la salida (por ejemplo, pantalla o archivo de imagen)
set terminal png size 800,600
set output 'grafico2.png'

set xrange [-20: 0]


# Graficar los puntos experimentales y la expresión teórica
plot "error_12.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "Método 1", \
	"error_22.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "Método 2" , \
	"error_32.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "Método 3", \



