# Configurar el tipo de gráfico
set title "log(Comparison)"
set xlabel "log(tau)"
set ylabel "Error"
set grid

# Elegir la salida (por ejemplo, pantalla o archivo de imagen)
set terminal png size 800,600
set output 'grafico.png'

# Ajuste lineal para Simpson en el rango [-3:-1]
set xrange [-3:-1]
f_simpson(x) = a*x + b
fit f_simpson(x) "simp_data.txt" using 1:2 via a,b

# Ajuste lineal para Trapecio en el rango [-5:-2]
set xrange [-5:-2]
f_trap(x) = c*x + d
fit f_trap(x) "trap_data.txt" using 1:2 via c,d

# Configurar el tamaño de los puntos (puedes ajustar el número en 'pointsize' según el tamaño deseado)
set pointsize 0.5  # Aumentar tamaño de los puntos (1.5 es un valor más grande que el predeterminado de 1)

set xrange [-7:0]
# Plot con el ajuste lineal y los puntos grandes
plot "simp_data.txt" using 1:2 with linespoints title "Simpson", \
     "trap_data.txt" using 1:2 with linespoints title "Trapezoidal", \
     f_simpson(x) title "Simpson Linear Fit", \
     f_trap(x) title "Trapezoidal Linear Fit"
