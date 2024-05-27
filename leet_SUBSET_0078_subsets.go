func subsets(nums []int) [][]int {

    solutions := []func([]int)[][]int {
        // iterative_bruteforce,
        backtracking,
    }
    return solutions[0](nums)
}

func backtracking(nums []int) [][]int {

    N := len(nums)
    res := [][]int{}

    var Backtrack func(int, []int)
    Backtrack = func(i int, curr []int) {
        if i == N {
            res = append(res, append([]int{}, curr...))
            return
        }
        Backtrack(i + 1, curr)
        curr = append(curr, nums[i])
        Backtrack(i + 1, curr)
        curr = curr[:len(curr) - 1]
    }

    Backtrack(0, []int{})
    return res
}

func iterative_bruteforce(nums []int) [][]int {

    res := [][]int{ []int{} }

    for _, n := range nums {
        N := len(res)
        i := 0
        for i < N {
            res = append(res, append([]int{}, res[i]...))
            end := len(res) - 1
            res[end] = append(res[end], n)
            i++
        }
    }
    return res
}
/*
res.push_back(res[j]);
res.back().push_back(n);
*/
