func getWinner(arr []int, k int) int {
    hi := arr[0]
    len := len(arr)
    i := 0
    for i < len {
        if hi < arr[i] {
            hi = arr[i]
        }
        i++
    }
    if k >= len {
        return hi
    }
    count := 0
    res := arr[0]
    i = 1
    for i < len {
        if res < arr[i] {
            res = arr[i]
            count = 1
        } else {
            count++
        }
        if count == k {
            return res
        }
        i++
    }
    return hi
}
