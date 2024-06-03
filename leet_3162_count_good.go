func numberOfPairs(nums1 []int, nums2 []int, k int) int {

    res := 0
    i := 0
    for i < len(nums1) {
        j := 0
        for j < len(nums2) {
            mult := nums2[j] * k
            if nums1[i] % mult == 0 {
                res++
            }
            j++
        }
        i++
    }
    return res
}
