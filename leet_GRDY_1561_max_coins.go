func maxCoins(piles []int) int {

    sort.Sort(sort.Reverse(sort.IntSlice(piles)))
    i := 1
    res := 0
    for i < len(piles) - len(piles) / 3 {
        res += piles[i]
        i += 2
    }
    return res
}
