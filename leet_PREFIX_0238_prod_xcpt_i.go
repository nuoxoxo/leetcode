func productExceptSelf(nums []int) []int {
    N := len(nums)
    if N == 0 {
        return []int{}
    }
    L := make([]int, N)
    R := make([]int, N)
    L[0], R[0] = 1, 1
    res := make([]int, N)
    var i int
    i = 1
    for i < N {
        L[i] = L[i - 1] * nums[i - 1]
        R[i] = R[i - 1] * nums[N - i]
        i++
    }
    i = 0
    for i < N {
        res[i] = L[i] * R[N - 1 - i]
        i++
    }
    return res
}
