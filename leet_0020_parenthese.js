var isValid = function(s) {
    let len = s.length
    if (len == 0)   return true
    if (len == 1)   return false
    let rule = new Object()
    let punc = []
    rule['}'] = '{'
    rule[')'] = '('
    rule[']'] = '['
    for (let c of s) {
        if (punc.length > len - 1)
            return false
        if (!rule.hasOwnProperty(c)) {
            punc.unshift(c)
        } else {
            if (punc.length == 0)
                return false
            if (punc[0] != rule[c])
                return false
            punc.shift()
        }
    }
    if (punc.length != 0)
        return false
    return true
};
