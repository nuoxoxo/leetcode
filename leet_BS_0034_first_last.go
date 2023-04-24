func searchRange(nums []int, target int) []int {
    len := len(nums)
    r := len - 1
    l := 0
    for l <= r {
        mid := (r - l) / 2 + l
        // fmt.Println(mid, l, r)
        if nums[mid] == target {
            l = mid
            r = mid
            for l > -1 && target == nums[l] {
                l--
            }
            for r < len && target == nums[r] {
                r++
            }
            a := []int {l + 1, r - 1}
            return a
        }
        if nums[mid] < target {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    a := []int {-1, -1}
    return a
}
