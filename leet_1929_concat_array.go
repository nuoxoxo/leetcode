func getConcatenation(nums []int) []int {

    solutions := []func([]int)[]int{
        // oneliner,
        // verbose,
        using_copy,
    }
    return solutions[0](nums)
}


func verbose(nums[]int)[]int{

    N := len(nums)
    res := make([]int, N * 2)
    i := 0
    for i, n := range nums {
        res[i] = n
        res[N + i] = n
        i++
    }
    return res
}


func oneliner(nums []int) []int {

    return append(nums, nums ...)
}


func using_copy(nums[]int)[]int{

    N := len(nums)
    res := make([]int, N * 2)
    copy(res, nums)
    for i, n := range nums {
        res[N + i] = n
    }
    return res
}
