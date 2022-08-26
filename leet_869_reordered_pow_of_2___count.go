func reorderedPowerOf2(n int) bool {
    check := count_n(n)
    // fmt.Println(check)
    num := 0
    i := 0
    for num < 1e9 + 1 {
        num = int(math.Pow(2, float64(i)))
        temp := count_n(num)
        if check == temp {
            return true
        }
        i++
    }
    return false
}

func count_n(n int) [10] int {
    r := [10] int {} // auto 0-filled
    for n > 0 {
        r[n % 10]++
        n /= 10
    }
    return r
}
