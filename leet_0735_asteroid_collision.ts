function asteroidCollision( a /*asteroids*/: number[]): number[] {
    let Q: number[] = []
    let i: number = 0
    while (i < a.length) {
        if (Q.length == 0 || a[i] > -1 || Q.at(-1) < 0) {
            Q.push(a[i])
            ++i
        } else if (Q.at(-1) + a[i] == 0) {
            Q.pop()
            ++i
        } else if (Q.at(-1) + a[i] < 0) {
            Q.pop()
        } else {
            ++i
        }
    }
    return Q
};
