func minEatingSpeed(piles []int, h int) int {
    sort.Ints(piles)
    M := piles[len(piles) - 1]
    L := 1
    R := M
    res := M
    for L < R {
        hours := 0
        mid := (R - L) / 2 + L
        for _, p := range piles {
            hours += (p + mid - 1) / mid
        }
        if (hours > h) {
            L = mid + 1
        } else {
            if (res > mid) {
                res = mid
            }
            R = mid
        }
    }
    return res
}
