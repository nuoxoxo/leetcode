func pivotInteger(n int) int {
    l, r := 0, n
    var i int
    for l <= r {
        mid := (r - l) / 2 + l
        L, R := 0, 0
        i = 0
        for i <= mid {
            L += i
            i++
        }
        i = mid
        for i <= n {
            R += i
            i++
        }
        if L == R {
            return mid
        }
        if L < R {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    return -1
}
