# Configuración de salida para pantalla interactiva
set terminal wxt size 1200,800 enhanced persist

# Activar modo de interacción con el ratón
set mouse

# Definir la función
f(x) = x**2 - 5*sin(2*pi*x)*cos(4*x)

# Establecer rango inicial de visualización
set xrange [-1:1]   # Mostrar solo el intervalo [-1, 1] de la función en el eje x
set yrange [-10:10] # Limitar el eje y para mantener la gráfica visible

# Configurar detalles de visualización
set title "Gráfica de f(x) con zoom interactivo"
set xlabel "x"
set ylabel "f(x)"
set grid
set samples 1000     # Aumentar la resolución de la gráfica para mayor detalle

# Comando para graficar
plot f(x) with lines title "f(x) = x^2 - 5*sin(2*pi*x)*cos(4*x)"

# Mantener la gráfica abierta para hacer zoom y exploración
pause -1
