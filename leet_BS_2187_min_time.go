func minimumTime(time []int, totalTrips int) int64 {
    sort.Ints(time)
    l := 0
    r := time[0] * totalTrips
    for l < r {
        mid := l + (r - l) / 2
        trips := 0
        for _, t := range time {
            trips += mid / t
        }
        if trips >= totalTrips {
            r = mid
        } else {
            l = mid + 1
        }
    }

    return int64(l)
}
