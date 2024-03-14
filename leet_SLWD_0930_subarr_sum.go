func numSubarraysWithSum(nums []int, goal int) int {
    N := len(nums)
    if N == 1 {
        if nums[1] == goal {
            return 1
        }
        return 0
    }
    l, r, curr, G := 0, 0, 0, 0
    for r < N {
        curr += nums[r]
        for curr > goal {
            curr -= nums[l]
            l++
        }
        G += r - l + 1
        r++
    }
    if goal == 0 {
        return G
    }
    l, r, curr = 0, 0, 0
    Gminus1 := 0
    for r < N {
        curr += nums[r]
        for curr > goal - 1 {
            curr -= nums[l]
            l++
        }
        Gminus1 += r - l + 1
        r++
    }
    return G - Gminus1
}
