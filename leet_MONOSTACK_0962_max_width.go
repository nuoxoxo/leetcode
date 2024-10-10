func maxWidthRamp(nums []int) int {
    res := 0
    var arr []int
    for i := 0; i < len(nums); i++ {
        if len(arr) == 0 || nums[i] < nums[arr[len(arr) - 1]] {
            arr = append(arr, i)
        }
    }
    for i := len(nums) - 1; i > -1 ; i-- {
        for len(arr) > 0 && nums[i] >= nums[arr[len(arr) - 1]] {
            // res = i - arr[len(arr) - 1] > res ? i - arr[len(arr) - 1] : res
            // no ternary in Go
            diff := i - arr[len(arr) - 1]
            if res < diff {
                res = diff
            }
            arr = arr[:len(arr) - 1]
        }
    }
    return res
}
