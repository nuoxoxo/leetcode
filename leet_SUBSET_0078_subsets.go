func subsets(nums []int) [][]int {

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
