var nearestValidPoint = function(x, y, points) {
    let res, idx, dix
    res = idx = 1e9
    for (let i = 0; i < points.length; i++){
        let p = points[i]
        if (y == p[1]){
            dif = Math.abs(x - p[0])
            if (dif < res){
                res = dif
                idx = i
            }
        }
        else if (x == p[0]){
            dif = Math.abs(y - p[1])
            if (dif < res){
                res = dif
                idx = i
            }
        }
        if (!res)
            return i
    }
    if (idx == 1e9) return -1
    return idx
};
