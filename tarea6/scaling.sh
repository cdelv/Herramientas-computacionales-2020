mpic++ integral_MPI.cpp

for nproc in {1..6}; do
 
	echo -n "$nproc  ";
	mpirun -np $nproc --oversubscribe ./a.out | tail -n 1;
done > scaling.txt
    
awk 'BEGIN {TS=1.0;} { if(NR==1) TS=$2;  print $1, $2, TS/$2, TS/$2/$1}' scaling.txt > metrics.txt
echo "Metrics saved to: metrics.txt"

echo "Done"
