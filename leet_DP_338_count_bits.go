func countBits(n int) []int {
    E := make([]int, n+1)
    for i := 0; i < n+1; i++ {
        E[i] = E[i/2] + i%2
    }
    return E
};
