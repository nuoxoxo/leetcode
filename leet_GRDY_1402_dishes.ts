function maxSatisfaction(satisfaction: number[]): number {
        satisfaction.sort((a, b) => {return a - b})
        let len = satisfaction.length
        let tmp = 0
        let res = 0
        let cur = 0
        let i = len
        while (--i > -1) {
            cur += tmp + satisfaction[i]
            if (cur < 1) {
                break
            }
            tmp += satisfaction[i]
            res = res > cur ? res : cur
        }
        return res
};
