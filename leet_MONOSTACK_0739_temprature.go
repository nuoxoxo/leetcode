func dailyTemperatures(temperatures []int) []int {
    Solutions := []func([]int) []int {
        Monotonic_stack_backward,
        // Monotonic_stack_forward,
    }
    return Solutions[ rand.Intn(len(Solutions)) ]( temperatures )
}

func Monotonic_stack_forward (t []int) []int {
    res := make([]int, len(t))
    stack := []int{}
    i := 0
    for i < len(t) {
        for len(stack) > 0 && t[ stack[len(stack) - 1] ] < t[i] {
            res[ stack[len(stack) - 1] ] = i - stack[len(stack) - 1]
            stack = stack[:len(stack) - 1]
        }
        stack = append(stack, i)
        i++
    }
    return res
}

func Monotonic_stack_backward (t[]int) []int {

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
