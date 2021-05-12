set terminal pngcairo
set grid
set style line 1 lc rgb "blue" lt 1 lw 1 pt 7 ps 0.5
set style line 2 lc rgb "red" lt 2 lw 1 pt 7 ps 0.5

set xrange [0:*]
set yrange [0:*]
set xlabel 'Cores'
f(x)=x

set title 'Speedup vs Cores'
set out 'Speedup.png'
plot 'metrics.txt'u 1:3 w l ls 1 t 'Speedup', f(x) w l ls 2 t 'Speedup ideal'
