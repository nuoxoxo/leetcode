function relativeSortArray(arr1: number[], arr2: number[]): number[] {
    let D: { [key: number]: number } = {};
    let tail: number[] = [];
    let res: number[] = [];

    for (const n of arr1) {
        if (!arr2.includes(n)) {
            tail.push(n);
        }
    }
    tail.sort((a, b) => a - b);

    for (const n of arr1) {
        if (!D.hasOwnProperty(n)) {
            D[n] = 1;
        } else {
            D[n]++
        }
    }

    for (const n of arr2) {
        res.push(...Array(D[n]).fill(n));
    }

    return res.concat(tail);
};
