# Configurar el tipo de gráfico
set title "Error según el método"
set xlabel "(h)"
set ylabel "(error relativo)"
set grid


# Elegir la salida (por ejemplo, pantalla o archivo de imagen)
set terminal png size 800,600
set output 'grafico2.png'



plot "disparo_h_0.01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "Método 1", \



