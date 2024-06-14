func minIncrementForUnique(nums []int) int {

    solutions := []func([]int) int{
        Greedy,
    }
    return solutions[0](nums)
}

func Greedy(nums[]int) int {

    sort.Ints(nums)
    N := len(nums)
    res := 0
    for i, n := range nums {
        if i == N - 1 {
            break
        }
        if n >= nums[i + 1] {
            diff := n - nums[i + 1] + 1
            nums[i + 1] += diff
            res += diff
        }
    }
    return res
}
