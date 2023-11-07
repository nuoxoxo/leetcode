func eliminateMaximum(dist []int, speed []int) int {
    time := make([]int, len(dist))
    i := 0
    for i < len(dist) {
        time[i] = (dist[i] + speed[i] - 1) / speed[i]
        i++
    }
    sort.Ints(time)
    res := 0
    for _, t := range time {
        if res == t {
            break
        }
        res++
    }
    return res
}
