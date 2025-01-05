f(x,y)= x - x*x - x*y
g(x,y)= 3*y - x*y - 2*y*y
splot f(x,y),g(x,y) 
set cntrparam levels 0
set contour
replot
set xrange [-3:3]
set yrange [-3:3]
unset surface
set view map
set xlabel " X"
set ylabel " Y"
set terminal png
set output "figure2.png"
replot
