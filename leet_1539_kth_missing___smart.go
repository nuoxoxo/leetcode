func findKthPositive(arr []int, k int) int {
    for _, n := range arr {
        if n <= k {
            k++
        }
    }
    return k
}
