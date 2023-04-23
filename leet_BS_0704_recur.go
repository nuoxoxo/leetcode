func search(nums []int, target int) int {
    return helper(nums, target, 0, len(nums) - 1)
}

func helper(a []int, k int, l int, r int) int {
    if len(a) < 1 || l > r {
        return -1
    }
    mid := (r - l) / 2 + l
    if a[mid] == k {
        return mid
    }
    if a[mid] < k {
        return helper(a, k, l + 1, r)
    }
    return helper(a, k, l, r - 1)
}
