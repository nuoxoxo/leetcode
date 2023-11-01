function sortByBits(arr: number[]): number[] {

    arr.sort((a, b) => {
        let x = counter(a)
        let y = counter(b)
        if (x == y)
            return a - b
        return x - y
    })
    return arr
};

var counter = function(n): number {
    let c = 0
    while (n != 0) {
        c += n & 1
        n >>= 1
    }
    return c
}
