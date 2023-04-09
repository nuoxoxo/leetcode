function successfulPairs(spells: number[], potions: number[], success: number): number[] {
    let E = new Array(spells.length).fill(0)
    potions.sort((a, b) => {return a - b})
    let i = -1;
    while (++i < spells.length) {
        let l = 0
        let r = potions.length - 1
        while (l <= r) {
            let mid = l + Math.floor((r - l) / 2)
            if (spells[i] * potions[mid] < success) {
                l = mid + 1
            } else {
                r = mid - 1
            }
        }
        E[i] = potions.length - r - 1
    }
    return E
};

