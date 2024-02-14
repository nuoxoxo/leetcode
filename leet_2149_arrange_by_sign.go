func rearrangeArray(nums []int) []int {
    Solutions := []func([]int)[]int{
        // Solution_slice,
        Solution_array,
    }
    return Solutions[0](nums)
}

func Solution_array (nums []int) []int {
    N := len(nums)
    res := make([]int, N)
    posindex := 0
    negindex := 1
    for _, n := range nums {
        if n < 0 {
            res[ negindex ] = n
            negindex += 2
        } else {
            res[ posindex ] = n
            posindex += 2
        }
    }
    return res
}

func Solution_slice (nums []int) []int {
    var P []int
    var N []int
    for _, n := range nums {
        if n < 0 {
            N = append(N, n)
        } else {
            P = append(P, n)
        }
    }
    i := 0
    res := []int{}
    for i < len(N) {
        res = append(res, P[i])
        res = append(res, N[i])
        i++
    }
    return res
}
