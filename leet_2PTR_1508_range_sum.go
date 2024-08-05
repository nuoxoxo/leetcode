func rangeSum(nums []int, n int, left int, right int) int {
    N := len(nums)
    temp := []int{}
    L := 0
    for L < N {
        R := L
        windowSum := 0
        for R < N {
            windowSum += nums[R]
            temp = append(temp, windowSum)
            R++
        }
        L++
    }
    sort.Ints(temp)
    fmt.Println(temp)
    res := 0
    if right > len(temp) {
        right = len(temp)
    }
    MOD := 1000000007
    for _, n := range temp[left - 1 : right] {
        res += n//(n % MOD)
        res %= MOD
    }
    return res
}
