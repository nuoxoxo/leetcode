

int tabulate(int);
int recurse(int);

int fib(int n){

    int ( * Solutions[2]) (int) = {
        tabulate,
        // recurse, // TLE
    };
    return Solutions[0](n);
}

int recurse(int n) {

    if (n < 2)
        return n;
    return recurse(n-1) + recurse(n-2);
}

int tabulate(int n){

    if (n < 2)
        return n;
    int tr[n + 1];
    tr[0] = 0;
    tr[1] = 1;
    int i = 1;
    while (++i < n + 1)
        tr[i] = tr[i - 1] + tr[i - 2];
    return tr[n];
}
