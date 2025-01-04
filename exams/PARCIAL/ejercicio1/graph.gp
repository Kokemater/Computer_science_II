# Configurar el tipo de gráfico
set title "Grafica f(x)"
set xlabel "x"
set ylabel "f(x)"
set grid

set xrange[-5: 5]
set yrange[-20:30]
PI = 3.14159265358979323846
f(x) = (3*PI*PI - 6*PI*x + PI*PI*x + 3*x*x - 2*PI*x*x + x*x*x)
f_prime(x) = -6*PI + PI*PI + 6*x - 4*PI*x + 3*x*x;
u(x) = f(x)/f_prime(x)

# Elegir la salida (por ejemplo, pantalla o archivo de imagen)
set terminal png size 800,600
set output 'grafico.png'

# Graficar los puntos experimentales y la expresión teórica
plot f(x) with lines linecolor rgb "red" title "f(x)",\
	u(x) with lines linecolor rgb "blue" title "u(x)"