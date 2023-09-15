function minCostConnectPoints(points: number[][]): number {
    let pq = []
    let p0 = points.shift()
    let res = 0
    for (let p of points) {
        let dist = Man(p, p0)
        pq.push([dist, p])
    }
    pq.sort((a, b) => a[0] - b[0])
    while (pq.length) {
        let [dist, coor] = pq.shift()
        res += dist
        let i = -1
        while (++i < pq.length) {
            pq[i][0] = Math.min(pq[i][0], Man(pq[i][1], coor))
        }
        pq.sort((a, b) => a[0] - b[0])
    }
    return res
};

const Man = (L:number[], R:number[]) => {
    return Math.abs(L[0] - R[0]) + Math.abs(L[1] - R[1])
}
