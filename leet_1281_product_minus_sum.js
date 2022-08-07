var subtractProductAndSum = function(n) {
    let p = 1, t = 0, k
    while (n) {
        k = n % 10
        p *= k
        t += k
        n = Math.floor(n /= 10)
    }
    return p - t
};
