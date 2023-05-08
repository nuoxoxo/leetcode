function stringMatching(words: string[]): string[] {
    let res: string[] = []
    for (let sub of words) {
        for (let w of words) {
            if (sub != w && w.includes(sub)) {
                res.push(sub)
                break
            }
        }
    }
    return res
};
