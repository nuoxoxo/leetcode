func countDigits(num int) int {
    tmp := num
    res := 0
    for tmp != 0 {
        n := tmp % 10
        if num % n == 0 {
            res += 1
        }
        tmp /= 10
    }
    return res
}
