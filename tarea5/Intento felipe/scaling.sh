g++ -fopenmp integration.cpp -o integration.x
NS=1000000

echo "Starting strong scaling with system size: $NS"

for NTH in 1 2 3 4 5 6 7 8 16 32; do
	echo -n "$NTH  ";
	./integration.x 0 10 $NS $NTH | head -n 1;
done > scaling_$NS.txt

echo "Computing parallel metrics from file scaling_$NS.txt ..."

awk 'BEGIN {TS=1.0;} { if(NR==1) TS=$2;  print $1, $2, TS/$2, TS/$2/$1}' scaling_$NS.txt > metrics_$NS.txt

echo "Metrics saved to: metrics_$NS.txt"

echo "Done"
