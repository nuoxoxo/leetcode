func longestSubstring(s string, k int) int {

    Solutions := []func(string, int)int{
        Brute_force,
    }
    return Solutions[0](s, k)
}

func Brute_force(s string, k int) int {
    N := len(s)
    end := 26
    if end > N {
        end = N
    }
    uniqueChars := 1
    res := 0
    for uniqueChars < end + 1 {
        D := make(map[byte]int)
        l := 0
        for r, c := range s {
            D[byte(c)] += 1
            for len(D) > uniqueChars {
                D[s[l]] -= 1
                if D[s[l]] == 0 {
                    delete(D, s[l])
                }
                l += 1
            }
            all := true
            for _, v := range D {
                if v < k {
                    all = false
                }
            }
            if all && res < r - l + 1 {
                res = r - l + 1
            }
        }
        uniqueChars += 1
    }
    return res

}
