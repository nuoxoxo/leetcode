func checkSubarraySum(nums []int, k int) bool {

    seen := make(map[int]bool)
    running := 0
    mod := 0
    for _, n := range nums {
        running += n
        tmp := running % k
        if seen[tmp] {
            return true
        }
        seen[mod] = true
        mod = tmp
    }
    return false
}
