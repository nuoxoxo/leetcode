func findErrorNums(nums []int) []int {
    Solutions := []func([]int)[]int{
        Solution_DP,
        Solution_Sorting_1pass,
    }
    return Solutions[ rand.Intn(len(Solutions)) ] (nums)
}
func Solution_Sorting_1pass(nums[]int)[]int{
    fmt.Println("/Solution_Sorting_1pass")
    res := []int{0,0}
    sort.Ints(nums)
    if nums[len(nums) - 1] == len(nums) {
        res[1] = 1
    } else {
        res[1] = len(nums)
    }
    for i := 1; i < len(nums); i++ {
        if nums[i] == nums[i - 1] {
            res[0] = nums[i]
        } else if nums[i] > nums[i - 1] + 1 {
            res[1] = nums[i - 1] + 1
        }
    }
    return res
}
func Solution_DP( nums[]int )[]int{
    fmt.Println("/Solution_DP")
    res := []int{0,0}
    DP := make([]int, len(nums))
    i := 0
    for i < len(nums) {
        DP[ nums[i] - 1 ]++
        i++
    }
    i = 0
    for i < len(nums) {
        if DP[i] == 2 {
            res[0] = i + 1
        } else if DP[i] == 0 {
            res[1] = i + 1
        }
        i++
    }
    return res
}
