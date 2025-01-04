# Configurar el tipo de gráfico
set title "Error según el método"
set xlabel "(h)"
set ylabel "(error relativo)"
set grid


# Elegir la salida (por ejemplo, pantalla o archivo de imagen)
set terminal png size 800,600
set output 'grafico2.png'

set xrange [-9: 1]
set yrange [-10: 1]

plot "error_diff_2.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "Método 1", \
	"error_diff_3.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "Método 2"



