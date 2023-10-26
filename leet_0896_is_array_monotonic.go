func isMonotonic(nums []int) bool {
    length := len(nums)
    if length < 3 {
        return true
    }
    flag := 0
    i := -1
    for i < length - 2 {
        i++
        if flag == 0 {
            if nums[i] < nums[i + 1] {
                flag = 1
            }
            if nums[i] > nums[i + 1] {
                flag = 2
            }
        } else if (flag == 1 && nums[i] > nums[i + 1]) || (flag == 2 && nums[i] < nums[i + 1]) {
            return false
        }
    }
    return true
}
