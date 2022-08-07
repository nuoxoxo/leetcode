function isAnagram(s: string, t: string): boolean {
    let ss = [...s].sort().join('')
    let tt = [...t].sort().join('')
    return ss === tt
};
