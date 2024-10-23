func maxWidthRamp(nums []int) int {
    Q := []int{}
    N := len(nums)
    i := 0
    for i < N {
        if len(Q) == 0 || nums[Q[ len(Q) - 1 ]] > nums[i] {
            Q = append(Q, i)
        }
        i++
    }
    i = N - 1
    res := 0
    for i > -1 {
        for len(Q) > 0 && nums[Q[ len(Q) - 1 ]] <= nums[i] {
            if res < i - Q[len(Q) - 1] {
                res = i - Q[len(Q) - 1]
            }
            Q = Q[:len(Q) - 1]
        }
        i--
    }
    return res
}
