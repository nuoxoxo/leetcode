function validateStackSequences(pushed: number[], popped: number[]): boolean {
    let idx = 0
    let a = []
    for (let n of pushed) {
        a.push(n)
        while (a.length ^ 0 && a[a.length - 1] == popped[idx]) {
            a.pop()
            ++idx
        }
    }
    return a.length == 0
};
