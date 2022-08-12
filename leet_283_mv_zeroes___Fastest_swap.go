func moveZeroes(nums []int)  {
    size := len(nums)
    if size == 0 {
        return 
    }
    i, x := 0, 0 // x is slow, i moves fast
    for i < size {
        if nums[i] != 0 {
            if i != x {
                tmp := nums[i]
                nums[i] = nums[x]
                nums[x] = tmp
            }
            x++
        }
        i++
    }
}
