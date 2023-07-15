func longestSubsequence(arr []int, diff int) int {
    d := make(map[int]int)
    res := 0
    for i := 0; i < len(arr); i++ {
        d[arr[i]] = d[arr[i] - diff] + 1
        if d[arr[i]] > res {
            res = d[arr[i]]
        }
    }
    return res
}
