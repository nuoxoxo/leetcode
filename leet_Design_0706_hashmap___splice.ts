class MyHashMap {
    private keys: number[] // must 
    private vals: number[] // have
    constructor() {
        this.keys = new Array()
        this.vals = new Array()
    }

    put(key: number, value: number): void {
        let idx = this.keys.indexOf(key)
        if (idx === -1) {
            this.keys.push(key)
            this.vals.push(value)
            return
        }
        this.vals[idx] = value
    }

    get(key: number): number {
        let idx = this.keys.indexOf(key)
        if (idx === -1)
            return -1
        return this.vals[idx]
    }

    remove(key: number): void {
        let idx = this.keys.indexOf(key)
        if (idx === -1)
            return
        this.vals.splice(idx, 1)
        this.keys.splice(idx, 1)
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * var obj = new MyHashMap()
 * obj.put(key,value)
 * var param_2 = obj.get(key)
 * obj.remove(key)
 */
