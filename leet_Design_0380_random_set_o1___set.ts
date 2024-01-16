class RandomizedSet {
    S: Set<number>
    constructor() {
        this.S = new Set()
    }

    insert(val: number): boolean {
        if (this.S.has(val))
            return false
        this.S.add(val)
        return true
    }

    remove(val: number): boolean {
        if ( ! this.S.has(val))
            return false
        this.S.delete(val)
        return true
    }

    getRandom(): number {
        return [...this.S][ Math.floor(Math.random() * this.S.size) ]
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */
