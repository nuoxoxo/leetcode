func subarraysWithKDistinct(nums []int, k int) int {
    K := subarr_with_no_more_than_k_distinct(nums, k)
    Kminus1 := subarr_with_no_more_than_k_distinct(nums, k - 1)
    return K - Kminus1
}

func subarr_with_no_more_than_k_distinct(nums []int, k int) int {

    D := map[int]int{}
    l := 0
    res := 0
    for r, n := range nums {
        D[n]++
        for len(D) > k {
            D[nums[l]]--
            if D[nums[l]] == 0 {
                delete(D, nums[l])
            }
            l++
        }
        res += r - l + 1
    }
    return res
}

