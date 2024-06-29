func getAncestors(n int, edges [][]int) [][]int {

    /*
    [0,3],[0,4],
    [1,3],
    [2,4],[2,7],
    [3,5],[3,6],[3,7],
    [4,6]

    - look at all 2nd-positions: 0, 1, 2 have no ancestors
    - from (0,3) (1,3) we know 3 has two: 0, 1
    - from (0,4) (2,4) we know 4 has two: 0, 2
    - but these having direct ancestors are coincident
    - for eg. 5 has 3 ancestors:
        - degree-1 ---> 3
        - degree-2 ---> 0,1
        - we can think this way: [5]--1-->[3](0,1) so 1+2
    - 6 has 5 ancestors:
        - degree-1 ---> 3,4
        - degree-2 ---> 0,1,2
        - we can think this way:
            - [6]--1-->[3](0,1)
            - [6]--1-->[4](0,2) so a set(3,4,0,1,2)
    - 7 has 4:
        - [7]--1-->[2]
        - [7]--1-->[3](0,1) so a set(2,3,0,1)
    */

    // adjacency list - init
    // ADJ := [][]int{}
    ADJ := make([][]int, n)

    // adjacency list, for each child of a immediate parent, save the parent
    for _, e := range edges {
        src, des := e[0], e[1]
        ADJ[ des ] = append(ADJ[des], src)
    }

    // def. DFS
    var DFS func(int, map[int]bool, map[int]bool)
    DFS = func(node int, SEEN map[int]bool, path map[int]bool) {
        if ! SEEN[node] {
            SEEN[node] = true
            path[node] = true
        }
        for _, next := range ADJ[node] {
            if ! SEEN[next] {
                DFS(next, SEEN, path)
            }
        }
    }

    // get to the bottom of node inside [0,n-1]
    node := 0
    res := [][]int{}
    for node < n {
        SEEN := make(map[int]bool, n)
        parents := make(map[int]bool, n)
        for _, parent := range ADJ[node] {
            if !SEEN[parent] {
                DFS(parent, SEEN, parents)
            }
        }
        temp := []int{}
        for parent, ok := range parents {
            if ok {
                temp = append(temp, parent)
            }
        }
        sort.Ints(temp)
        res = append(res, temp)
        node++
    }
    return res
}
