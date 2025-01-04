# Configurar el tipo de gráfico
set title "Comparación Off(A(K)) vs Teórica"
set xlabel "Iteración K"
set ylabel "Off(A^(K)) / Off(A)"
set grid

set xrange[3: 4]
r0 = 1.5e-15;
V0 = 50e6;
force(x) = (-V0*r0)*(r0**2/x**2 + r0/x)*exp(-x/r0);
f(x) = force(r0* x) - 0.01*force(r0)


# Elegir la salida (por ejemplo, pantalla o archivo de imagen)
set terminal png size 800,600
set output 'grafico.png'

# Graficar los puntos experimentales y la expresión teórica
plot f(x) with lines linecolor rgb "red" title "Expresión cota teórica"
