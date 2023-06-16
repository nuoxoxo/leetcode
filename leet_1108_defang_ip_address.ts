function defangIPaddr(address: string): string {
    let res: string = ''
    for (let c of address) {
        if (c == '.') {
            res += '[.]'
        } else {
            res += c
        }
    }
    return res
};
