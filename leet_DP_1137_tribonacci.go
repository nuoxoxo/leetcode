func tribonacci(n int) int {

    Solutions := []func(int)int{
        // Tabulation1,
        // Tabulation2,
        Recurse, 
    }
    return Solutions[0](n)
}

func Recurse(n int) int {

    if n < 2 {
        return n
    }
    if n == 2 {
        return 1
    }
    return Recurse(n - 3) + Recurse(n - 2) + Recurse(n - 1)
}

func Tabulation2(n int) int {

    tr := []int{0, 1, 1}
    if n < 3 {
        return tr[n]
    }
    i := 3
    for i < n + 1 {
        tr = append(tr, tr[i - 3] + tr[i - 2] + tr[i - 1])
        i++
    }
    return tr[n]
}

func Tabulation1(n int) int {

    tr := make([]int, n + 1)
    if n == 0 {
        return n
    }
    if n < 3 {
        return 1
    }
    tr[0] = 0
    tr[1] = 1
    tr[2] = 1
    i := 3
    for i < n + 1 {
        tr[i] = tr[i - 3] + tr[i - 2] + tr[i - 1]
        i++
    }
    return tr[n]
}
