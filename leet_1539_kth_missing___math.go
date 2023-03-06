func findKthPositive(arr []int, k int) int {
    if k < arr[0] {
        return k
    }
    k = k - arr[0] + 1
    i := 1
    for ; i < len(arr); i++ {
        diff := arr[i] - arr[i - 1]
        if diff == 1 {
            continue
        }
        if k < diff {
            break
        }
        k -= diff - 1
        // i++
    }
    return arr[i - 1] + k
}
