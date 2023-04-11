function findComplement(num: number): number {
    // let s = (num >> 0).toString(2) // also works
    // let s = num.toString(2) // also works
    let s = (num >>> 0).toString(2)
    let r = ''
    for (let c of s) {
        r += (c == '0') ? '1' : '0' 
    }
    // console.log(r)
    return parseInt(r, 2);
};
