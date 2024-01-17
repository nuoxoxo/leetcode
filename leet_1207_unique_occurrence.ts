function uniqueOccurrences(arr: number[]): boolean {
    const solns: (
        (arr: number []) => boolean
    )[] = [
        Solution_map_values,
        Solution_count_sorted
    ]
    const n = Math.floor(Math.random() * solns.length)
    return solns[ n ](arr)
};

const Solution_count_sorted = (arr: number[]): boolean => {

    console.log('/Solution_count_sorted')
    const occ: number[] = []
    arr.sort((a,b)=>a-b)
    let i = 0
    while (i < arr.length) {
        let j = i
        while (j < arr.length && arr[i] == arr[j]) {
            ++j
        }
        occ.push(j - i)
        i = j
    }
    occ.sort((a,b)=>a-b)
    i = -1
    while (++i < occ.length - 1) {
        if (occ[i] == occ[i + 1])
            return false
    }
    return true
}

const Solution_map_values = (arr: number[]): boolean => {

    console.log('/Solution_map_values')
    const D: { [key:number]:number } = {}
    const occ = []
    for (const n of arr) {
        if (D.hasOwnProperty(n)) {
            D[n]++
        } else {
            D[n] = 1
        }
    }
    for (const k in D) {
        occ.push( D[k] )
    }
    return (new Set(occ)).size == occ.length
}
