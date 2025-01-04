# Archivo: potential.gp
set terminal pngcairo size 800,600
set output 'potential_plot.png'

# Configuración de la gráfica
set title "Double Potential Function"
set xlabel "r (m)"
set ylabel "Potential V(r)"
set grid

# Define la función
sigma = 1e-9
V0 = 1
potential(r) = V0 * ((sigma/r)**6 - exp(-r/sigma))

# Rango de r para la gráfica
set xrange [1e-10:5e-9]
set yrange [-1:2]

# Graficar la función
plot potential(x) title "V(r)" lw 2 lc rgb "blue"
