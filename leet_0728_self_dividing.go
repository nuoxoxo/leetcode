func selfDividingNumbers(left int, right int) []int {
    n := left
    res := make([]int, 0)
    for n < right + 1 {
        if isSD(n) {
            res = append(res, n)
        }
        n++
    }
    return res
}

func isSD(num int) bool {
    n := num
    for n > 0 {
        div := n % 10
        if div == 0 || num % div != 0 {
            return false
        }
        n /= 10
    }
    return true
}
