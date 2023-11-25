function restoreArray(adjacentPairs: number[][]): number[] {
    let D: {[key: number]: number[]} = []
    let indegree: { [key:number]: number } = []
    for (let [a, b] of adjacentPairs) {

        // way 2
        D[a] = D[a] || []
        D[b] = D[b] || []
        D[a].push(b)
        D[b].push(a)

        indegree[a] = (indegree[a] || 0) + 1
        indegree[b] = (indegree[b] || 0) + 1

        // way 1 : old way is verbose
        /*
        if (!D[a])
            D[a] = []
        if (!D[b])
            D[b] = []
        D[a].push(b)
        D[b].push(a)
        if (!indegree.hasOwnProperty(a))
            indegree[a] = 1
        else 
            indegree[a]++
        if (!indegree.hasOwnProperty(b))
            indegree[b] = 1
        else 
            indegree[b]++
        */
    }
    let curr: number | null = null
    for (let [k, v] of Object.entries(indegree)) {
        console.log(k, v)
        if (v === 1)
            curr = parseInt(k)
    }
    if (!curr) {
        console.log(curr)
        return []
    }
    let len:number = adjacentPairs.length + 1
    let res: number[] = []
    let seen: Set<number> = new Set<number>()
    let i = -1
    while (++i < len) {
        seen.add(curr)
        res.push(curr)
        for (let n of D[curr] || []) {
            indegree[n]--
            if (!seen.has(n) && indegree[n] < 2) {
                curr = n
                break
            }
        }
    }
    return res
};
