func kthSmallest(matrix [][]int, k int) int {

    var g [] int

    for _, row := range matrix {
        g = append(g, row ...)
    }
    sort.Ints(g)
    return g[k - 1]
}
