func longestIdealString(s string, k int) int {
    lens := make([]int, 26)
    i := 0
    for i < 26 {
        lens[i] = 0
        i++
    }
    N := len(s)
    i = 0
    for i < N {
        idx := int(s[i]) - int('a')
        L := idx - k
        if L < 0 {
            L = 0
        }
        R := idx + k + 1
        if R > 26 {
            R = 26
        }
        temp := lens[L:R]
        best := temp[0]
        for _, n := range temp {
            if best < n {
                best = n
            }
        }
        lens[idx] = best + 1
        i++
    }
    best := lens[0]
    for _, n := range lens {
        if best < n {
            best = n
        }
    }
    return best
}
