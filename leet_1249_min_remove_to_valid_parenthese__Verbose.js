/**
 * @param {string} s
 * @return {string}
 */

var minRemoveToMakeValid = function(s) {
    let len = s.length
    let arr = []
    let res = ""
    let i = -1
    while (++i < len){
        if (s[i] == '('){
            arr.push(i)
        }
        if (s[i] == ')'){
            if (arr.length != 0){
                arr.pop()
            } else {
                s = s.substr(0, i) + '/' + s.substr(i + 1)
            }
        }
    }    
    while (arr.length != 0){
        let tmp = arr.pop()
        s = s.substr(0, tmp) + '/' + s.substr(tmp + 1)
    }
    for (let c of s){
        if (c != '/')
            res += c
    }
    return res
};
