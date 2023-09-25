var findTheDifference = function(s, t) {
    let lens = s.length
    if (lens == 0)  return t[0]
    let c = t.charCodeAt(t.length - 1)
    let i = -1
    while (++i < lens){
        c += t.charCodeAt(i)
        c -= s.charCodeAt(i)
    }
    return String.fromCharCode(c)
};
