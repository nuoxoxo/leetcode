func bagOfTokensScore(tokens []int, power int) int {
    sort.Ints(tokens)
    i := 0
    j := len(tokens) - 1
    res, cur := 0, 0
    for i < j + 1 {
        if tokens[i] < power + 1 {
            cur += 1;
            if cur > res {
                res = cur
            }
            power -= tokens[i]
            i++
        } else if cur > 0 {
            cur -= 1
            power += tokens[j]
            j -= 1
        } else {
            break
        }
    }
    return res
}
