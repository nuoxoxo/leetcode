function findWords(words: string[]): string[] {
    const res: string[] = [];
    for (const w of words) {
        if (checker("qwertyuiop", w) || checker("asdfghjkl", w) || checker("zxcvbnm", w)) {
            res.push(w);
        }
    }
    return res;
}

function checker(charset: string, word: string): boolean {
    for (const c of word) {
        if (charset.indexOf(c.toLowerCase()) === -1) {
            return false;
        }
    }
    return true;
}
