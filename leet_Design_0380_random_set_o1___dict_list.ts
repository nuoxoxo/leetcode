class RandomizedSet {

    private getindexbyvalue: {[key: string]: number}
    private arr: Array<number>

    constructor() {
        this.getindexbyvalue = {}
        this.arr = []      
    }

    insert(val: number): boolean {
        if ( this.getindexbyvalue.hasOwnProperty( val ) )
            return false
        this.arr.push(val)
        this.getindexbyvalue[val] = this.arr.length - 1
        return true
    }

    remove(val: number): boolean {
        if ( ! this.getindexbyvalue.hasOwnProperty( val ))
            return false
        const index = this.getindexbyvalue[val]
        this.arr[index] = this.arr[ this.arr.length - 1 ]
        this.arr.pop()
        delete this.getindexbyvalue[ val ]
        this.getindexbyvalue[ this.arr[index] ] = index
        return true
    }

    getRandom(): number {
        return this.arr[ Math.floor(Math.random() * this.arr.length ) ]
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */
