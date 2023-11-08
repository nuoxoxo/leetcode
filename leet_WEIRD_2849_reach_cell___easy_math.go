func isReachableAtTime(sx int, sy int, fx int, fy int, t int) bool {
    if sx == fx && sy == fy {
        return t != 1
    }
    dx := int(math.Abs(float64(sx - fx)))
    dy := int(math.Abs(float64(sy - fy)))
    if dx > t || dy > t {
        return false
    }
    return true
}
