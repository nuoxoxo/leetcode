func differenceOfSum(nums []int) int {
    res1 := 0
    res2 := 0
    for _, n := range nums {
        res1 += n
        for n != 0 {
            res2 += n % 10
            n /= 10
        }
    }
    diff := res1 - res2
    if diff < 0 {
        return -diff
    }
    return diff
}
