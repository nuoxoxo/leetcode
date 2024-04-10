function isIsomorphic(s: string, t: string): boolean {
    const solutions: ((s: string, t: string) => boolean)[] = [
        Mapless_using_indexOf,
        // Tabulation,
    ]
    return solutions[ 0 ]( s, t )
}

function Mapless_using_indexOf(s: string, t: string): boolean {
    const N = s.length
    if (N != t.length)
        return false
    let i = 0
    while (++i < N) {
        if (s.indexOf(s[i]) !== t.indexOf(t[i]))
            return false
    }
    return true
}

function Tabulation(s: string, t: string): boolean {
    const N: number = s.length
    if (N !== t.length) {
        return false
    }
    const s2t: number[] = new Array(128).fill(0)
    const checked: boolean[] = new Array(128).fill(false)
    let i: number = 0
    while (i < N) {
        const L: string = s[i]
        const R: string = t[i]
        if (s2t[L.charCodeAt(0)] !== 0 && s2t[L.charCodeAt(0)] !== R.charCodeAt(0)) {
            return false
        }
        if (s2t[L.charCodeAt(0)] === 0 && checked[R.charCodeAt(0)]) {
            return false
        }
        s2t[L.charCodeAt(0)] = R.charCodeAt(0)
        checked[R.charCodeAt(0)] = true
        i++
    }
    return true
}
