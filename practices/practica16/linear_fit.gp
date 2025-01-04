# Configurar el tipo de grfico
set title "Error relativo derivada 3"
set xlabel "log_10 (h)"
set ylabel "log_10(error relativo)"
set grid

# salida 
set terminal png size 800,600
set output 'grafico3_fit.png'

# Ajuste lineal
set xrange [-4:0]
f_1(x) = a*x + b
fit f_1(x) "derivada3.txt" using 1:2 via a,b

# Ajuste lineal
set xrange [-4:0]
f_2(x) = c*x + d
fit f_2(x) "derivada3.txt" using 1:3 via c,d

# Ajuste lineal
set xrange [-4:0]
f_3(x) = e*x + f
fit f_3(x) "derivada3.txt" using 1:4 via e,f

set xrange [-20: 1]
set yrange [-10:1]


# Graficar los puntos experimentales y la expresion teorica
plot "derivada3.txt" u 1:2 w lp title "centr3", \
	"derivada3.txt" u 1:3 w lp title "progr3" , \
	"derivada3.txt" u 1:4 w lp title "regr3", \
    f_1(x) title "Ajuste metodo 1", \
    f_2(x) title "Ajuste metodo 2", \
    f_3(x) title "Ajuste metodo 3"