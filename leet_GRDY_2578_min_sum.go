func splitNum(num int) int {
    arr := []int{}
    for num > 0 {
        n := num % 10
        arr = append(arr, n)
        num /= 10
    }
    sort.Ints(arr)
    L, R := 0, 0
    for i, n := range arr {
        if i % 2 == 0 {
            L = L * 10 + n
        } else {
            R = R * 10 + n
        }
    }
    return L + R
}
