

int tabulate(int);
int recurse(int);

int tribonacci(int n){

    int ( * Solutions[2]) (int) = {
        tabulate,
        // recurse, // TLE
    };
    return Solutions[0](n);
}

int recurse(int n) {

    if (n < 2)
        return n;
    if (n == 2)
        return 1;
    return recurse(n-1) + recurse(n-2) + recurse(n-3);
}

int tabulate(int n){

    if (!n)
        return n;
    if (n < 3)
        return 1;
    int tr[n + 1];
    tr[0] = 0;
    tr[1] = tr[2] = 1;
    int i = 2;
    while (++i < n + 1)
        tr[i] = tr[i - 1] + tr[i - 2] + tr[i - 3];
    return tr[n];
}
