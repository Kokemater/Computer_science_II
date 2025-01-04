# Archivo: potential.gp
set terminal pngcairo size 800,600
set output 'potential_plot.png'

# Configuración de la gráfica
set title "function"
set xlabel "r (m)"
set ylabel "Potential V(r)"
set grid

K = 0.25 * 1e-3;
Re = 200000;
D = 0.3;
f(x) = (2*log10((2.51)/(sqrt(x) *Re) + K/(3.71*D))+ 1/sqrt(x));

# Rango de r para la gráfica
set xrange [0.01:0.03]

# Graficar la función
plot f(x) title "f(x)" lw 2 lc rgb "blue"
