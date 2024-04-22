func validPath(n int, edges [][]int, source int, destination int) bool {
    Solutions := []func(int, [][]int, int, int) bool {
        BFS,
    }
    return Solutions[0](n, edges, source, destination)
}

func BFS(n int, edges [][]int, source int, destination int) bool {

    if source == destination {
        return true
    }
    Q := []int{source}
    Seen := map[int]bool{source: true}
    ADJ := map[int][]int{}
    for _, edge := range edges {
        u := edge[0]
        v := edge[1]
        ADJ[u] = append(ADJ[u], v)
        ADJ[v] = append(ADJ[v], u)
    }
    for len(Q) != 0 {
        u := Q[0]
        if u == destination {
            return true
        }
        Q = Q[1:]
        for _, v := range ADJ[u] {
            if !Seen[v] {
                Q = append(Q, v)
                Seen[v] = true
            }
        }
    }
    return false
}
