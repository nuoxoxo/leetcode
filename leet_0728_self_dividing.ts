function selfDividingNumbers(left: number, right: number): number[] {
    let n: number = left
    let res: number[] = []
    while (n < right + 1) {
        if (isSD(n))
            res.push(n)
        ++n
    }
    return res
};

function isSD(num: number) {
    let n: number = num
    while (n) {
        let div: number = n % 10
        if ( div === 0 || num % div != 0)
            return false
        n = Math.floor(n / 10)
    }
    return true
}
