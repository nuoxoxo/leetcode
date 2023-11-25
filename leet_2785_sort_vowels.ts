function sortVowels(s: string): string {
    let v: string = 'aeiouAEIOU'
    let vo: string[] = []
    for (let c of s)
        if (v.includes(c))
            vo.push(c)
    vo.sort()
    let res: string = ''
    let i = 0
    for (let c of s) {
        if ( ! v.includes(c)) {
            res += c
        } else {
            res += vo[i]
            i += 1
        }
    }
    return res
        
};
