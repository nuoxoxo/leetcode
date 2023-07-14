func longestSubsequence(arr []int, diff int) int {
    d := make(map[int]int)
    res := 0
    for _, n := range arr {
        d[n] = d[n - diff] + 1
    }
    for _, v := range d {
        if res < v {
            res = v
        }
    }
    return res
}

