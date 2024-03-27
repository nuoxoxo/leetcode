func numSubarrayProductLessThanK(nums []int, k int) int {

    Solutions := []func([]int,int)int{
        TwoPointers,
    }
    return Solutions[0](nums, k)
}

func TwoPointers(nums[]int, k int) int {

    if k < 2 {
        return 0
    }
    res := 0
    prod := 1
    L := 0
    for R, n := range(nums) {
        prod *= n
        for prod >= k {
            prod /= nums[L]
            L++
        }
        res += R - L + 1
    }
    return res
}
