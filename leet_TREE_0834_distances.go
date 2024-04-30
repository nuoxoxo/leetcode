func sumOfDistancesInTree(n int, edges [][]int) []int {
    return Rerooting(n, edges)
}

func Rerooting(N int, edges [][]int) []int{

    subtree := make([]int, N)
    dists := make([]int, N)

    ADJ := make(map[int][]int)
    for _, edge := range edges {
        u, v := edge[0], edge[1]
        ADJ[u] = append(ADJ[u], v)
        ADJ[v] = append(ADJ[v], u)
    }

    // func -> calculate subtree[node] & dists[node]
    var getInfoForSubtreeAndDists func(node, parent int)
    getInfoForSubtreeAndDists = func(node, parent int) {
        subtree[node] = 1
        dists[node] = 0
        for _, v := range ADJ[node] {
            if v != parent {
                getInfoForSubtreeAndDists(v, node)
                subtree[node] += subtree[v]
                dists[node] += dists[v] + subtree[v]
            }
        }
    }

    res := make ([]int, N)
    for i := range res {
        res[i] = -1
    }
    getInfoForSubtreeAndDists(0, -1)
    res[0] = dists[0]

    // func -> reroot each node
    var rerooting func(node, parent, parent_nodes, parent_dists int)
    rerooting = func(node, parent, parent_nodes, parent_dists int) {
        for _, v := range ADJ[node] {
            if v != parent {
                other_nodes := subtree[node] - subtree[v] + parent_nodes
                other_dists := dists[node] - (dists[v] + subtree[v]) + parent_nodes + parent_dists
                res[v] = other_dists + other_nodes + dists[v]
                rerooting(v, node, other_nodes, other_dists)
            }
        }
    }
    rerooting(0, -1, 0, 0)
    return res
}
