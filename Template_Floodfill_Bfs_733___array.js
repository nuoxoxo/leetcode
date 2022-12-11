/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} newColor
 * @return {number[][]}
 */
var floodFill = function(img, x, y, nc) {
    let oc = img[x][y]
    if (oc == nc)
        return img
    let c = img[0].length
    let r = img.length
    let dq = [[x, y]]
    while (dq.length != 0) {
        
        console.log(dq)
        let tmp = dq.shift()
        let L = tmp[0]
        let R = tmp[1]
        img[L][R] = nc
        if (L + 1 < r && img[L + 1][R] == oc)
            dq.push([L + 1, R])
        if (L - 1 > -1 && img[L - 1][R] == oc)
            dq.push([L - 1, R])
        if (R + 1 < c && img[L][R + 1] == oc)
            dq.push([L, R + 1])
        if (R - 1 > -1 && img[L][R - 1] == oc)
            dq.push([L, R - 1])
    }
    return img
};
