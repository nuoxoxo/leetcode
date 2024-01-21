func rob(nums []int) int {
    Solutions := []func([]int) int {
        Solution_Constant_Space,
        Solution_Topdown_DP,
        Solution_Classic_DP,
    }
    return Solutions[ rand.Intn(len( Solutions ))/*1*/ ]( nums )
}

func Solution_Topdown_DP (nums[]int)int{
    fmt.Println("/Solution_Topdown_DP")
    memo := make([]int, len(nums))
    for i := range memo {
        memo[i] = -1
    }

    // define a recursive func here
    var dp func([]int, int)int
    dp = func(nums[]int, i int)int{
        if i < 0 {
            return 0
        }
        if memo[i] > -1 {
            return memo[i]
        }
        curr := max(dp(nums, i - 1), nums[i] + dp(nums, i - 2))
        memo[i] = curr
        return curr
    }

    return dp(nums, len(nums) - 1)
}

func Solution_Classic_DP (nums[]int)int {
    fmt.Println("/Solution_Classic_DP")
    size := len(nums)
    if size < 3 {
        return max_of_slice(nums...)
    }
    dp := make([]int, size)
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])
    dp[2] = max(nums[2] + nums[0], nums[1])
    for i := 3; i < size; i++ {
        dp[i] = max_of_slice(dp[i - 1], dp[i - 2] + nums[i])
    }
    return dp[size - 1]
}

func Solution_Constant_Space (nums[]int)int {
    fmt.Println("/Solution_Constant_Space")
    if len(nums) < 3 {
        return max_of_slice (nums...)
    }
    curr := 0
    prevprev := 0
    for _, n := range nums {
        temp := curr
        curr = max(curr, prevprev + n)
        prevprev = temp
    }
    return curr
}

// helper: max of arr

func max_of_slice (nums...int) int {
    res := nums[0]
    for _, n := range nums[1:] {
        if res < n {
            res = n
        }
    }
    return res
}
