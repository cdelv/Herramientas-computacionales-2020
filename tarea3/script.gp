set term pdf
set out 'CPUtime.pdf'
set log xy
set xlabel 'Matrix size (N)'
set ylabel 'CPU time [s]'
f(x) = A*x**B
A = 0.0001
fit f(x) 'eigenvalues.txt' via A, B
plot 'eigenvalues.txt' w lp t 'datos', 'eigenvaluesO3.txt' w lp t 'datos O3', f(x) t 'fit'
