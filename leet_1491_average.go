func average(salary []int) float64 {
    hi := math.MinInt
    lo := math.MaxInt
    sum := 0
    for _, n := range salary {
        if n > hi {
            hi = n
        }
        if n < lo {
            lo = n
        }
        sum += n
    }
    return float64(sum - hi - lo) / float64(len(salary) - 2)
}
