function backspaceCompare(s: string, t: string): boolean {
    let [ss, tt] = [[], []]
    for (let c of s) {
        if (c != '#') {
            ss.push(c)
        } else if (ss.length) {
            ss.pop()
        }
    }
    for (let c of t) {
        if (c != '#') {
            tt.push(c)
        } else if (tt.length) {
            tt.pop()
        }
    }
    return ss.join() == tt.join()
};
