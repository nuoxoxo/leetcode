func countGoodTriplets(arr []int, a int, b int, c int) int {
    res := 0
    L := len(arr)
    for i := 0; i < L - 2; i++ {
        for j := i + 1; j < L - 1; j++ {
            for k := j + 1; k < L; k++ {
                if math.Abs(float64(arr[i] - arr[j])) <= float64(a) &&
                    math.Abs(float64(arr[j] - arr[k])) <= float64(b) &&
                    math.Abs(float64(arr[k] - arr[i])) <= float64(c) {
                    res += 1
                }
            }
        }
    }
    return res
}
