for Size in 1 10 50 100; do
    echo -n "$Size "
    ./eigenvalues.x $Size 50 0
done > eigenvalues.txt
