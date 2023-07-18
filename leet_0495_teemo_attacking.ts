function findPoisonedDuration(timeSeries: number[], duration: number): number {

    let res: number = duration * timeSeries.length
    let i: number = 0
    while (++i < timeSeries.length) {
        res -= Math.max(0, duration - (timeSeries[i] - timeSeries[i - 1]))
    }
    return res
};
