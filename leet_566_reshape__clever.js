var matrixReshape = function(M, r, c) {
    let co = M[0].length
    if (r*c != co*M.length) return M
    let E = []
    let i = -1
    while (++i < r)
        E.push(new Array(c))
    i = -1
    while (++i < r * c)
        E[Math.floor(i / c)][i % c] = M[Math.floor(i / co)][i % co]
    return E
};
