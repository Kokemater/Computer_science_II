# Configurar el tipo de gráfico
set title "N iterations (Gauss vs Jacobi)"
set xlabel "Precission"
set ylabel "N iterations"
set logscale x
set grid

# Elegir la salida (por ejemplo, pantalla o archivo de imagen)
set terminal png size 800,600
set output 'grafico.png'
set xrange [1e-12:1e-3]
# Plot con el ajuste lineal y los puntos grandes
plot "n_iterations.txt" using 1:2 with linespoints title "Jacobi", \
     "n_iterations.txt" using 1:3 with linespoints title "gauss", \

