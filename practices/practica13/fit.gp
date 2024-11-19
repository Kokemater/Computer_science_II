set term  png
set output 'grafica_ajuste.png'
f(x) = A + B*x
set xrange [-3:-1]
fit f(x) 'simp_data.txt' u 1:2 via A, B
g(x) = C + D*x 
set xrange [-5:-2]
fit g(x) 'Integrales.txt' u 1:3 via C,D
h(x) = E + F*x
set xrange [-7:-2]
fit h(x) 'Integrales.txt' u 1:2 via E,F
set yrange [-15:0]
set xrange [-8:0]
deriv1(x) = (2*x-1)*sin(x)*sin(x) +(x*x-x+1)*2*sin(x)*cos(x)
deriv3(x) = 6* (-1 + 2* x)* cos(x)**2 + 4* (1 + 2* x - 2* x*x)* cos(x)*sin(x)+ 6* (1 - 2* x)* sin(x)**2
errtrap(x) = 2*x +log10(abs((deriv1(6)-deriv1(-6)))/12)
errsimp(x) = 4*x +log10(1/180*abs(deriv3(6) -deriv3(-6)))
plot "Integrales.txt" u 1:2 w lp, "Integrales.txt" u 1:3 w lp, "Integrales.txt" u 1:4 w lp, f(x), g(x), h(x),errtrap(x),errsimp(x)
#plot errtrap(x), errsimp(x)  # , g(x),h(x)
set term wxt