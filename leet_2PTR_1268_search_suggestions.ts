function suggestedProducts(products: string[], searchWord: string): string[][] {
    products.sort()
    let res: string[][] = []
    let n:number = products.length
    let wl:number = searchWord.length
    let L = 0
    let R = n - 1
    let i = -1
    while (++i < wl) {
        let c = searchWord[i]
        while (L <= R && (i >= products[L].length || products[L][i] < c))
            L++
        while (L <= R && (i >= products[R].length || products[R][i] > c))
            R--
        if (L > R) {
            res.push([])
        } else {
            const end = L + 3 > R + 1 ? R + 1 : L + 3
            res.push(products.slice(L, end))
        }
    }
    return res
};
