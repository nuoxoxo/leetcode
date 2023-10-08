func checkPerfectNumber(num int) bool {
    if num < 2 {
        return false
    }
    res := 1
    sqr := math.Sqrt(float64(num))
    n := 2
    for n < int(sqr) + 1 {
        if num % n != 0 {
            n++
            continue
        }
        res += n + num / n
        n++
    }
    if num % n == 0 && int(sqr) >= n {
        res += n
    }
    // fmt.Println(sqr, int(sqr), res, num, n)
    return res == num
}
