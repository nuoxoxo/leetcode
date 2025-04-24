func countCompleteSubarrays(nums []int) int {
    Solutions := []func([]int)int{
        direct_solution,
        using_counter,
    }
    return Solutions[0](nums)
}

func direct_solution(nums[]int)int{
    s := make(map[int]bool)
    for _,n := range nums { s[n] = true }
    UN := len(s)
    N := len(nums)
    res := 0
    fmt.Println(UN)
    for L := 0; L < N; L++ {
        ss := make(map[int]bool)
        for R := L; R < N; R++ {
            ss[nums[R]] = true
            if len(ss) == UN { res++ }
        }
    }
    return res
}

func using_counter(nums[]int)int{
    s := make(map[int]bool)
    for _,n := range nums { s[n] = true }
    UN := len(s)
    D := make(map[int]int)
    N := len(nums)
    L, R := 0,0
    res := 0
    for L < N {
        D[nums[L]]++
        for len(D) == UN {
            D[nums[R]]--
            if D[nums[R]] == 0 {
                delete(D, nums[R])
            }
            R++
            res += N - L
        }
        L++
    }
    return res
}

