func findTheCity(n int, edges [][]int, distanceThreshold int) int {
    /*

    distanceThreshold = 4

       (0)
        |
       3|
        |
       (1)
       /  \
     1/    \4
     /      \
    (2)-----(3)
        1

    city 0: 0-1/cost 3, 0-2/cost 3+1
    city 1: 1-0/cost 3, 1-2/cost 1, 1-3/cost 4
    city 2: 2-0/cost 1+3, 2-1/cost 1, 2-3/cost 1
    city 3: 3-1/cost 4, 3-2/cost 1
            ^ return 3 coz 3>0
    */
    Solutions := []func(int, [][]int, int)int{
        Floyd_Warshall_DP,
    }
    return Solutions[0](n, edges, distanceThreshold)
}

func Dijkstra(n int, edges [][]int, distanceThreshold int) int {

    // todo
    return 42
}

func Floyd_Warshall_DP(n int, edges [][]int, distanceThreshold int) int {

    INF := int(1e6)
    W := make([][]int, n)
    for u := range W {
        W[u] = make([]int, n)
        for v := range W[u] {
            W[u][v] = INF
        }
        W[u][u] = 0
    }
    for _, e := range edges {
        W[e[0]][e[1]] = e[2]
        W[e[1]][e[0]] = e[2]
    }
    k := 0
    for k < n {
        for u := range W {
            for v := range W[u] {
                bypass_w := W[u][k] + W[k][v]
                if W[u][v] > bypass_w {
                    W[u][v] = bypass_w
                }
            }
        }
        k++
    }
    res := 42
    min_reachables := n
    for u := range W {
        reachables := 0
        for v := range W[u] {
            if W[u][v] <= distanceThreshold {
                reachables++
            }
        }
        if min_reachables >= reachables {
            min_reachables = reachables
            res = u
        }
    }
    return res


}



