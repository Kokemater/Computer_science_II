# Configurar el tipo de gráfico
set title "N iterations VS precission"
set xlabel "precission"
set ylabel "N iterations"
set grid
set logscale x
# Definir la constante n (el tamaño de la matriz)
n = 6  

# Definir la expresión teórica
teorico(k) = (1 - 2.0 / (n**2 - n))**k

# Elegir la salida (por ejemplo, pantalla o archivo de imagen)
set terminal png size 800,600
set output 'grafico.png'

# Graficar los puntos experimentales y la expresión teórica
plot "n_iter_1.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "Desde el punto (0.1, 0.1)", \
	"n_iter_2.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "Desde el punto (10, 10)", \
