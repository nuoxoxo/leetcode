function minimumEffortPath(heights: number[][]): number {
        const R = heights.length
        const C = heights[0].length
        const dirs: number[][] = [
            [0, 1], [0, -1], [1, 0], [-1, 0]
        ]
        const pq: number[][] = [
            [0, 0, 0]
        ]
        const seen: Set<string> = new Set()
        let coor: string = ''
        while (pq.length > 0) {
            pq.sort((a, b) => a[0] - b[0])
        
            const [eff, r, c] = pq.shift()!
            coor = `${r},${c}`
        
            if (seen.has(coor)) {
                continue
            }
            seen.add(coor)
            
            if (r === R - 1 && c === C - 1) {
                return eff
            }
            for (let [dr, dc] of dirs) {
                const rr = r + dr
                const cc = c + dc
                coor = `${rr},${cc}`
                if (rr < 0 || rr === R || cc < 0 || cc === C || seen.has(coor)) {
                    continue
                }
        
                const temp = Math.max(eff, Math.abs(heights[r][c] - heights[rr][cc]))
                pq.push([temp, rr, cc])
            }
        }
        
        return 0
};
