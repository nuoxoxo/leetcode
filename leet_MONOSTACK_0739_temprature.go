func dailyTemperatures( t []int) []int {
    res := make([]int, len(t))
    stack := []int{}
    i := len(t) - 1
    for i > -1 {
        for len(stack) != 0 && t[ stack[len(stack) - 1] ] <= t[ i ] {
            stack = stack[:len(stack) - 1]
        }
        if len(stack) > 0 {
            res[i] = stack[len(stack) - 1] - i
        }
        stack = append(stack, i)
        i--
    }
    return res
}
