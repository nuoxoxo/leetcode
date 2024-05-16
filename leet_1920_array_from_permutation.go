func buildArray(nums []int) []int {

    res := []int{}
    for n := range nums {
        // assert -1 < n < N
        res = append(res, nums[nums[n]])
    }
    return res
}
