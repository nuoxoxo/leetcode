func minPatches(nums []int, n int) int {

    solutions := []func([]int, int) int {
        // no_int64,
        using_int64_explicitly,
    }
    return solutions[0](nums, n)
}

func using_int64_explicitly(nums []int, n int) int {

    res := 0
    var R int64 = 0
    for _, num := range nums {
        for R < int64(n) && R + 1 < int64(num) {
            R += R + 1
            res++
        }
        R += int64(num)
    }
    for R < int64(n) {
        R += R + 1
        res++
    }
    return res
}

func no_int64(nums []int, n int) int {
    res, R := 0, 0 // will also work
    for _, num := range nums {
        for R < n && R + 1 < num {
            R += R + 1
            res++
        }
        R += num
    }
    for R < n {
        R += R + 1
        res++
    }
    return res
}
