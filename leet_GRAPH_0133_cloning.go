/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */

func cloneGraph(node *Node) *Node {
    if node == nil {
        return nil
    }
    res := & Node {Val: node.Val, Neighbors: []*Node{}}
    deque := []*Node{ node }
    adj := map[ *Node ] *Node {}
    adj[ node ] = res
    for len(deque) != 0 {
        curr := deque[0]
        deque = deque[1:]
        for _, neigh := range curr.Neighbors {
            _, ok := adj[neigh]
            if !ok {
                adj[neigh] = & Node {neigh.Val, []*Node{}}
                deque = append(deque, neigh)
            }
            adj[curr].Neighbors = append(adj[curr].Neighbors, adj[neigh])
        }
    }
    return res
}
