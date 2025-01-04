# Configurar el tipo de gráfico
set title "Comparación Off(A(K)) vs Teórica"
set xlabel "Iteración K"
set ylabel "Off(A^(K)) / Off(A)"
set grid

set xrange[-5:5]
teorico(x) = x*(x + 5) + 3 - exp(x)

# Elegir la salida (por ejemplo, pantalla o archivo de imagen)
set terminal png size 800,600
set output 'grafico.png'

# Graficar los puntos experimentales y la expresión teórica
plot teorico(x) with lines linecolor rgb "red" title "Expresión cota teórica"
