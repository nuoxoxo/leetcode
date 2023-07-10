func answerQueries(nums []int, queries []int) []int {
    sort.Ints(nums) 
    n := len(nums)
    m := len(queries)
    prefix := 0
    var pref []int
    res := make([]int, m) // auto-filled w/ 0
    for _, n := range nums {
        prefix += n
        pref = append(pref, prefix)
    }
    for i, q := range queries {
        tmp := 0
        j := 0
        for j < n {
            if pref[j] > q {
                break
            }
            tmp++
            j++
        }
        res[i] = tmp
    }
    return res
}
