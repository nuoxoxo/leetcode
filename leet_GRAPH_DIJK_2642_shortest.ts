class Graph {

    private adj: number[][][] = []

    constructor(n: number, edges: number[][]) {
        let i = -1
        while (++i < n)
            this.adj.push([])
        for (let e of edges) {
            let [node, dest, cost] = e
            this.adj[node].push([cost, dest])
        }
    }

    addEdge(edge: number[]): void {
        let [node, dest, cost] = edge
        this.adj[node].push([cost, dest])
    }

    shortestPath(node1: number, node2: number): number {
        let pq: number[][] = [[0, node1]]

        let D: number[] = []
        let i = -1
        while (++i < this.adj.length)
            D[i] = -1
        D[node1] = 0
        while (pq.length > 0) {
            let [dist, node] = pq.shift()!
            if (node === node2) {
                return dist
            }
            for (let [cost, idx] of this.adj[node]) {
                // either uninitialized or a shorter path is found
                if (D[idx] === -1 || dist + cost < D[idx]) {
                    D[idx] = dist + cost
                    pq.push([D[idx], idx])
                    pq.sort((a, b) => a[0] - b[0])
                }
            }
        }
        return D[node2]
    }
}

/**
 * Your Graph object will be instantiated and called as such:
 * var obj = new Graph(n, edges)
 * obj.addEdge(edge)
 * var param_2 = obj.shortestPath(node1,node2)
 */
