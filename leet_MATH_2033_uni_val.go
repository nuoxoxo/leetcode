func minOperations(grid [][]int, x int) int {
    Solutions := []func([][]int,int) int {
        median_and_flattened,
    }
    return Solutions[0](grid, x)
}

func median_and_flattened(g [][]int, x int) int {
    F := []int{}
    for _,r := range g {
        for _,n := range r {
            F = append(F,n)
        }
    }
    sort.Ints(F)
    N := len(F)
    median := F[N / 2]
    res := 0
    for _,n := range F {
        diff := n - median
        if diff < 0 { diff = -diff }
        if diff % x != 0 {
            return -1
        }
        res += diff / x
    }
    return res
}
