function isReachableAtTime(sx: number, sy: number, fx: number, fy: number, t: number): boolean {
    if (sx == fx && sy == fy)
            return t !== 1
        let dx = Math.abs(sx - fx)
        let dy = Math.abs(sy - fy)
        if (dx > t || dy > t)
            return false
        return true
};
