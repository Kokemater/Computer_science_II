
f(x,y) = x**3 + 6*y**2 - 76
g(x,y) = 8*x**3*y**2 + x*y - 1024

splot f(x,y),g(x,y) 
set cntrparam levels 0
set contour
replot
set xrange [2:4.5]
set yrange [-4:4]
unset surface
set view map
set xlabel " X"
set ylabel " Y"
set terminal jpeg
set output "figure2.jpg"
replot


