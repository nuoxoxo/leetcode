function eliminateMaximum(dist: number[], speed: number[]): number {
    let time: number[] = dist.map(
        (d, i) => Math.floor((d + speed[i] - 1) / speed[i])
    )
    time.sort((a, b) => a - b);
    let res = 0;
    for (let t of time) {
        if (res === t) {
            break;
        }
        res++;
    }
    return res;
};
