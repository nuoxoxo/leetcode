func reductionOperations(nums []int) int {
    /*
    sort.Ints(nums)
    // fmt.Println(nums)
    i := 1
    res := 0
    for i < len(nums) {
        if nums[i] != nums[i - 1] {
            res += len(nums) - i
        }
        i++
    }
    return res
    */

    // 👆 way 1
    // 👇 way 2

    sort.Ints(nums)
    // fmt.Println(nums)
    i := 1
    res := 0
    dist := 0
    for i < len(nums) {
        if nums[i] != nums[i - 1] {
            dist += 1
        }
        res += dist
        i++
    }
    return res
}
