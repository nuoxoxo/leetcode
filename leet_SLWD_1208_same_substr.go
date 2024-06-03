func equalSubstring(s string, t string, maxCost int) int {
    Solutions := []func(string, string, int) int {
        Sliding_window,
    }
    return Solutions[0](s, t, maxCost)
}

func Sliding_window(s string, t string, maxCost int) int {

    L := 0
    R := 0
    res := 0
    windowCost := 0
    N := len(s)
    for R < N {
        // diff := int(s[R] - t[R]) // note how ascii arithmetic works
        diff := int(s[R]) - int(t[R])
        if diff < 0 {
            diff *= -1
        }
        windowCost += diff
        for windowCost > maxCost {
            diff = int(s[L]) - int(t[L])
            if diff < 0 {
                diff *= -1
            }
            windowCost -= diff
            L++
        }
        if res < R - L + 1 {
            res = R - L + 1
        }
        R++
    }
    return res

}
