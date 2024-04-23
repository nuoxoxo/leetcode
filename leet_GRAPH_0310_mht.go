func findMinHeightTrees(n int, edges [][]int) []int {
    Solutions := []func(int, [][]int)[]int{
        GreedyBFS,
    }
    return Solutions[0](n, edges)
}

func GreedyBFS(N int, edges [][]int) []int {

    if N == 1 {
        return []int{0}
    }

    // Basic idea
    //  - finds the leaves of the tree iteratively,
    //  - until only the centroids remain ie. roots of the MHTs

    res := []int{}
    ADJ := map[int][]int{}
    for _, edge := range edges {
        u, v := edge[0], edge[1]
        ADJ[u] = append(ADJ[u], v)
        ADJ[v] = append(ADJ[v], u)
    }

    // var degrees [N]int
    //  ---> BUG : invalid array length N (solution.go)
    degrees := make([]int, N)

    i := 0
    for i < N {
        degrees[i] = len(ADJ[i])
        if degrees[i] == 1 {
            res = append(res, i)
            degrees[i]--
        }
        i++
    }

    for true {
        new_leaves := []int{}
        for _, u := range res {
            for _, v := range ADJ[u] {
                if degrees[v] > 0 {
                    degrees[v]--
                    if degrees[v] == 1 {
                        new_leaves = append(new_leaves, v)
                    }
                }
            }
        }
        // remove leaves until only the centroids ie. roots of MHTs remain
        //  - it is Greedy
        //  - reduce the tree's dimension in each iteration by removing leaves
        //  - once there are no new leaves, all there remains are centroids
        if len(new_leaves) == 0 {
            break
        }
        res = new_leaves
    }
    return res
}
