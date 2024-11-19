# Configurar el tipo de gráfico
set title "Comparación Off(A(K)) vs Teórica"
set xlabel "Iteración K"
set ylabel "Off(A^(K)) / Off(A)"
set grid

# Definir la constante n (el tamaño de la matriz)
n = 6  

# Definir la expresión teórica
teorico(k) = (1 - 2.0 / (n**2 - n))**k

# Elegir la salida (por ejemplo, pantalla o archivo de imagen)
set terminal png size 800,600
set output 'grafico.png'

# Graficar los puntos experimentales y la expresión teórica
plot "points.txt" using 1:2 with linespoints pointtype 7 pointsize 1.5 title "Datos Obtenidos", \
     teorico(x) with lines linecolor rgb "red" title "Expresión cota teórica"
