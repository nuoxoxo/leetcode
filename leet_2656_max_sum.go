func maximizeSum(nums []int, k int) int {
    sort.Ints(nums)
    n := nums[ len(nums) - 1 ]
    res := 0
    i := 0
    for i < k {
        i++
        res += n
        n += 1
    }
    return res
}
