class MapSum {

    // private M: object = {}
    private M: Record<string, number> = {}

    constructor() {
        this.M = {}
    }

    insert(key: string, val: number): void {
        this.M[key] = val
    }

    sum(prefix: string): number {
        let E: Array<[string, number]> = Object.entries(this.M)
        let res = E
            .filter(
                (e) => e[0].startsWith(prefix)
            ).reduce(
                (a, b) => a + b[1], 0
            )
        return res
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * var obj = new MapSum()
 * obj.insert(key,val)
 * var param_2 = obj.sum(prefix)
 */
