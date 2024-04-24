func fib(n int) int {

    Solutions := []func(int)int{
        Tabulation1,
        // Tabulation2,
        // Recurse,
    }
    return Solutions[0](n)
}

func Recurse(n int) int {

    if n < 2 {
        return n
    }
    return Recurse(n - 2) + Recurse(n - 1)
}

func Tabulation2(n int) int {

    tr := []int{0, 1}
    if n < 2 {
        return tr[n]
    }
    i := 2
    for i < n + 1 {
        tr = append(tr, tr[i - 2] + tr[i - 1])
        i++
    }
    return tr[n]
}

func Tabulation1(n int) int {

    tr := make([]int, n + 1)
    if n < 2 {
        return n
    }
    tr[0] = 0
    tr[1] = 1
    i := 2
    for i < n + 1 {
        tr[i] = tr[i - 2] + tr[i - 1]
        i++
    }
    return tr[n]
}
