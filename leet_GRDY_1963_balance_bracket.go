func minSwaps(s string) int {
    solutions := []func(s string)int{
        Greedy,
    }
    return solutions[0](s)
}

func Greedy(s string)int{
    eq, res := 0, 0
    for i := range s {
        if s[i] == '[' {
            eq++
        } else {
            eq--
        }
        if eq == -1 {
            eq = 1
            res++
        }
    }
    return res
}

