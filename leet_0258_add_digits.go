func addDigits(num int) int {
    for num > 9 {
        num = helper(num)
    }
    return num
}

func helper(n int) int {
    res := 0
    for n > 0 {
        res += n % 10
        n /= 10
    }
    return res
}
