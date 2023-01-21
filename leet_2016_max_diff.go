func maximumDifference(nums []int) int {
    mini := int(^uint(0) >> 1) // max int in golang
    res := -1
    for i := 0; i < len(nums); i++ {
        if nums[i] < mini {
            mini = nums[i]
        }
        if nums[i] > mini && nums[i] - mini > res {
            res = nums[i] - mini
        }
    }
    return res
}
