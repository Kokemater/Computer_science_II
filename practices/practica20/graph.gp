# Configurar el tipo de gráfico
set title " Método "
set xlabel "x"
set ylabel "u"
set grid


set terminal png size 800,600
set output 'graph.png'
set key left


# Graficar los puntos experimentales y la expresión teórica
plot "h01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.1'", \
	"h001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.01'" , \
	"h0001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.001'", \

# Configurar el tipo de gráfico
set title " Diferencia relativa con respecto a h = 0.001 "
set xlabel "x"
set ylabel "u"
set grid


set terminal png size 800,600
set output 'graph2.png'
set key left


# Graficar los puntos experimentales y la expresión teórica
plot "diff01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.1'", \
	"diff001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.01'" , \


# Configurar el tipo de gráfico
set title " Diferencia relativa con respecto al método del disparo. "
set xlabel "x"
set ylabel "u"
set grid


set terminal png size 800,600
set output 'graph3.png'
set key left


# Graficar los puntos experimentales y la expresión teórica
plot "error01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.1'", \
	"error001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.01'" , \
	"error0001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.001'" , \





# Configurar el tipo de gráfico
set title " Métodos Disparo y diferencias "
set xlabel "x"
set ylabel "u"
set grid


set terminal png size 800,600
set output 'graph4.png'
set key left


# Graficar los puntos experimentales y la expresión teórica
plot "h01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.1'", \
	"h001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.01'" , \
	"h0001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.001'", \
	"disparo01.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.1 disparo'", \
	"disparo001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.01 disparo'" , \
	"disparo0001.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "h = 0.001 disparo'", \
