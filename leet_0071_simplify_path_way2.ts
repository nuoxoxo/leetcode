function simplifyPath(path: string): string {
    let D = []
    let res = ''
    
    let i = -1
    while (++i < path.length) {
        if (path[i] == '/')
            continue
        let word = ''
        while (i < path.length && path[i] != '/') {
            word += path[i++]
        }
        if (word == '.')
            continue
        if (word == '..' && D.length)
        {
            D.pop()
        } else if (word != '..') {
            D.push(word)
        }
    }
    while (D.length) {
        let tmp = '/' + D.pop()
        res = tmp + res
    }
    return res == '' ? '/' : res
};
