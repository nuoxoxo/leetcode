function countDigits(num: number): number {
    let res = 0
    let tmp = num
    while (tmp != 0) {
        let n = tmp % 10
        if (num % n == 0) {
            res++
        }
        tmp = Math.floor(tmp / 10)
    }
    return res
};
