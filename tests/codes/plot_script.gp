set terminal pngcairo
set output 'plot.png'
set title 'Gráfico de x^2'
set xlabel 'x'
set ylabel 'y'
plot 'data.txt' with linespoints title 'x^2'
