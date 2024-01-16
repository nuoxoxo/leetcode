function arraysIntersection(arr1: number[], arr2: number[], arr3: number[]): number[] {
    let S = new Set(arr1.filter(
        n => arr2.includes(n) && arr3.includes(n)
    ))
    let res = []
    for (let n of [...arr1, ...arr2, ...arr3]) {
        if ( !S.has(n) ) {
            continue
        }
        S.delete(n)
        res.push(n)
    }
    return res
};
