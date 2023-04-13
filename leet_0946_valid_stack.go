func validateStackSequences(pushed []int, popped []int) bool {
    idx := 0
    a := []int {}
    for _, n := range pushed {
        a = append(a, n)
        for len(a) != 0 && a[len(a) - 1] == popped[idx] {
            a = a[:len(a) - 1]
            idx += 1
        }
    }
    return len(a) == 0
}
