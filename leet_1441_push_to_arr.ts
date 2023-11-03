function buildArray(target: number[], n: number): string[] {
    let res: string[] = []
    let cur: number = 0
    let i = 0
    while (++i && cur != target.length) {
        if (target[cur] == i) {
            ++cur
            res.push('Push')
        } else {
            res.push('Push', 'Pop')
        }
    }
    return res
};
