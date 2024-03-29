func countSubarrays(nums []int, k int) int64 {
    max := 0
    for _, n := range nums {
        if max < n {
            max = n
        }
    }
    var res int64 = 0
    fq := 0
    l := 0
    for r, n := range nums {
        if n == max {
            fq++
        }
        if fq >= k {
            for fq > k && l < r {
                if nums[l] == max {
                    fq--
                }
                l++
            }
            for nums[l] != max && l < r {
                l++
            }
            res += int64(l) + 1
        }
    }
    return res
}
