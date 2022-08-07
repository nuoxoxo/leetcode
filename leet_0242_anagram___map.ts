function isAnagram(s: string, t: string): boolean {
    if (s.length == t.length) {
        let ss : {[key : string] : number} = {}
        let tt : {[key : string] : number} = {}
        s.split('').forEach((c) => {
            ss[c] = (ss[c] | 0) + 1
        })
        t.split('').forEach((c) => {
            tt[c] = (tt[c] | 0) + 1
        })
        for (let key in ss) {
            if (ss[key] != tt[key])
                return false
        }
        return true
    }
    return false
};
