function flipAndInvertImage(image: number[][]): number[][] {
    let res = []
    for (let r of image) {
        let tmp = []
        for (let n of r.reverse()) {
            tmp.push(n ? 0 : 1)
        }
        res.push(tmp)
    }
    return res
};
