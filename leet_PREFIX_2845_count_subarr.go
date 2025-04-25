func countInterestingSubarrays(nums []int, modulo int, k int) int64 {
    Solutions := []func(nums []int, modulo int, k int) int64 {
        // On_square_TLE,
        using_prefix,
    }
    return Solutions[0](nums,modulo,k)
}

func using_prefix(nums []int, modulo int, k int) int64 {
    var res int64 = 0
    pref := 0
    D := make(map[int]int64)
    D[0] = 1
    for R,_ := range nums {
        // we count good subarrs that
        // end at this _ index (ie. idx of n)
        if nums[R] % modulo == k {
            pref++
        }
        remain := (pref - k) % modulo
        res += D[remain]
        D[pref % modulo]++
    }
    return res
}

func On_square_TLE(nums []int, modulo int, k int) int64 {
    var res int64 = 0
    for l,_ := range nums {
        // var tmp int64 = 0
        tmp := 0
        for r := l; r < len(nums); r++ {
            if nums[r] % modulo == k {
                tmp++
            }
            if tmp % modulo == k {
                res++
            }
        }
    }
    return res
}
