function checkPerfectNumber(num: number): boolean {
    if (num < 2) {
        return false;
    }
    const sqr = Math.sqrt(num);
    let n = 1;
    let res = 1;
    while (++n < sqr) {
        if (num % n !== 0) {
            continue;
        }
        res += n + num / n;
    }
    if (num % n === 0 && sqr >= n) {
        res += n;
    }
    return res === num;
};
