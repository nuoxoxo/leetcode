func allPathsSourceTarget(graph [][]int) [][]int {

    
    res := [][]int{}
    curr := []int{}
    Max := len(graph)
    var backtrack func(int)
    backtrack = func(node int) {
        curr = append(curr, node)
        if node == Max - 1 {
            // res = append(res, curr)
            //  - tricky part -> a copy should be appended
            res = append(res, append([]int{}, curr...))
        } else {
            for _, nxt := range graph[node] {
                backtrack(nxt)
            }
        }
        curr = curr[:len(curr) - 1]
    }
    backtrack(0)
    return res
}
