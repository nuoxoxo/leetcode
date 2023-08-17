function updateMatrix(mat: number[][]): number[][] {

    let c:number = mat[0].length
    let r:number = mat.length

    let D: number[][] = new Array(r)
    let dx: number[] = [ 0, 1, 0, -1]
    let dy: number[] = [-1, 0, 1,  0]

    let E: any[] = []
    let i: number  = -1
    let j: number

    while (++i < r) {
        let tmp = new Array(c).fill(-1)
        D[i] = tmp
    }
    i = -1
    while (++i < r) {
        j = -1
        while (++j < c){
            if (mat[i][j] == 0) {
                E.push( {x: i, y: j} )
                D[i][j] = mat[i][j]
            }
        }
    }

    while (true) {
        if (E.length == 0) {
            break
        }
        let tmp: any = E.shift()
        let k: number = -1
        while (++k < 4) {
            let tx: number = tmp.x + dx[k]
            let ty: number = tmp.y + dy[k]
            if (tx > -1 && ty > -1 && tx < r && ty < c && mat[tx][ty] == 1 && D[tx][ty] == -1) {
                D[tx][ty] = D[tmp.x][tmp.y] + 1
                E.push({x: tx, y: ty})
            }
        }
    }
    return D
};
