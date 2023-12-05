func numberOfWays(corridor string) int {
    res := 1
    sea := 0
    pls := 0
    mod := 1000000007
    for _, c := range corridor {
        if c == 'P' {
            if sea > 1 && sea % 2 == 0 {
                pls++
            }
        } else if c == 'S' {
            sea++
            res *= pls + 1
            res %= mod
            pls = 0
        }
    }
    if sea < 1 || sea % 2 == 1 {
        return 0
    }
    return res
}
