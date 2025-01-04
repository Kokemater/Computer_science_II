# Configurar el tipo de gráfico
set title "Error según el método"
set xlabel "log_10 (h)"
set ylabel "log_10(error)"
set grid


# Elegir la salida (por ejemplo, pantalla o archivo de imagen)
set terminal png size 800,600
set output 'grafico.png'


# Ajuste lineal para Simpson en el rango [-3:-1]
set xrange [-5:-1]
f_1(x) = a*x + b
fit f_1(x) "error_1.txt" using 1:2 via a,b

# Ajuste lineal para Trapecio en el rango [-5:-2]
set xrange [-4:-1]
f_2(x) = c*x + d
fit f_2(x) "error_2.txt" using 1:2 via c,d

# Ajuste lineal para Trapecio en el rango [-5:-2]
set xrange [-2: -1]
f_3(x) = e*x + f
fit f_3(x) "error_3.txt" using 1:2 via e,f


set xrange [-5: 0]


# Graficar los puntos experimentales y la expresión teórica
plot "error_1.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "Método 1", \
	"error_2.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "Método 2" , \
	"error_3.txt" using 1:2 with linespoints pointtype 7 pointsize 0.5 title "Método 3", \
	f_1(x) title "Ajuste método 1", \
    f_2(x) title "Ajuste método 2", \
	f_3(x) title "Ajuste método 3"


