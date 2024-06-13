func sortColors(nums []int)  {

    N := len(nums)
    l, r := 0, N - 1
    for l < N && nums[l] == 0 {
        l++
    }
    for r > -1 && nums[r] == 2 {
        r--
    }
    mid := l
    for mid <= r {
        if nums[mid] == 0 {
            nums[mid], nums[l] = nums[l], nums[mid]
            l++
        } else if nums[mid] == 2 {
            nums[mid], nums[r] = nums[r], nums[mid]
            r--
            mid--
        }
        mid++
    }
}
