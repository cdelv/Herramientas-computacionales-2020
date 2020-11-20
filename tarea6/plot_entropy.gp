set terminal pngcairo
set grid
set style line 1 lc rgb "blue" lt 1 lw 1 pt 7 ps 0.5

set xrange [0:*]
set yrange [0:*]
set xlabel 'Cores'

set title 'Speedup vs Cores'
set out 'Speedup.png'
plot 'metrics_1000000.txt'u 1:3 w l ls 1 t 'Speedup'
