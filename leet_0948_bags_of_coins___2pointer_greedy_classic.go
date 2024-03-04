func bagOfTokensScore(tokens []int, power int) int {
    sort.Ints(tokens)
    l := 0
    r := len(tokens) - 1
    res, pts := 0, 0
    for l <= r {
        if tokens[ l ] < power + 1 {
            pts += 1;
            if pts > res {
                res = pts
            }
            power -= tokens[ l ]
            l++
        } else if pts > 0 {
            pts -= 1
            power += tokens[ r ]
            r -= 1
        } else {
            break
        }
    }
    return res
}
