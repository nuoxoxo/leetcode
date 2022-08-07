var champagneTower = function(poured, query_row, query_glass) {
    res = []
    let i = -1, j
    while (++i < 102){
        let tmp = new Array(102)
        tmp.fill(0)
        res.push(tmp)
    }
    res[0][0] = poured
    i = -1
    while (++i < query_row + 1){
        j = -1
        while (++j < i + 1){
            if (res[i][j] > 1){
                let t = res[i][j] - 1
                res[i][j] = 1
                res[i + 1][j] = res[i + 1][j] + t / 2
                res[i + 1][j + 1] = res[i + 1][j + 1] + t / 2
            }
        }
    }
    return res[query_row][query_glass]
};
