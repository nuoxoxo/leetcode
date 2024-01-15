function findWinners(matches: number[][]): number[][] {

    const Solutions: ((matches: number[][]) => number[][])[] = [
        Solution_3sets,
        Solution_1dict
    ]
    const n = Math.floor(Math.random() * Solutions.length)
    return Solutions[ n ]( matches )
}

// Soln 1 - o(n) s(3n) ---> Using a win-set 
// and 2 loser-sets - one for 1-lost and an extra for more-than-1 loses
const Solution_3sets = (matches: number[][]): number[][] => {

    console.log('/3sets')
    const wins: Set<number> = new Set()
    const loss: Set<number> = new Set()
    const lss: Set<number> = new Set()
    for (let [w, l] of matches) {
        if (wins.has(l)) {
            wins.delete( l )
            loss.add( l )
        } else if (loss.has(l)) {
            loss.delete( l )
            lss.add( l )
        } else if ( ! lss.has(l)) {
            loss.add( l )
        }
        if ( ! loss.has(w) && ! lss.has(w)) {
            wins.add(w)
        }
    }
    return [
        [...wins].sort((a,b)=>a-b),
        [...loss].sort((a,b)=>a-b)
    ]
};

// Solution 2 - o(n) s(n)
// Only one dict/map will do the job
const Solution_1dict = (matches: number[][]): number[][] => {

    const P = new Object()
    for (let [w, l] of matches) {
        if (!P.hasOwnProperty(w)) {
            P[w] = 0
        }
        if (!P.hasOwnProperty(l)) {
            P[l] = 1
        } else {
            P[l] += 1
        }
    }
    const L:number[] = []
    const R:number[] = []
    for (const key in P) {
        if (P[key] == 0)
            L.push(parseInt(key))
        if (P[key] == 1)
            R.push(parseInt(key))
    }
    return [ L.sort((a,b)=>a-b), R.sort((a,b)=>a-b) ]
}

