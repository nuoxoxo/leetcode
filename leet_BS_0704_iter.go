func search(nums []int, target int) int {
    len := len(nums)
    if len == 1 {
        if nums[0] == target {
            return 0
        } else {
            return -1
        }
    }
    l := 0
    r := len - 1
    for l <= r {
        mid := (r - l) + l
        if nums[mid] == target {
            return mid
        }
        if nums[mid] < target {
            l++
        } else {
            r--
        }
    }
    return -1
}
