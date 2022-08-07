/**
 * @param {number[][]} mat
 * @return {number[][]}
 */
var updateMatrix = function(mat) {
    let c = mat[0].length
    let r = mat.length
    let D = new Array(r)
    let dx = [ 0, 1, 0, -1]
    let dy = [-1, 0, 1,  0]
    let E = []
    let i = -1
    let j
    while (++i < r) {
        let tmp = new Array(c).fill(-1)
        D[i] = tmp
    }
    i = -1
    while (++i < r){
        j = -1
        while (++j < c){
            if (mat[i][j] == 0){
                E.push( {x: i, y: j} )
                D[i][j] = mat[i][j]
            }
        }
    }
    while (true){
        if (E.length == 0)  break
        let tmp = E[0]
        E.shift()
        let k = -1
        while (++k < 4) {
            let tx = tmp.x + dx[k]
            let ty = tmp.y + dy[k]
            if (tx > -1 && ty > -1 && tx < r && ty < c && mat[tx][ty] == 1 && D[tx][ty] == -1) {
                D[tx][ty] = D[tmp.x][tmp.y] + 1
                E.push({x: tx, y: ty})
            }
        }
    }
    return D
};











