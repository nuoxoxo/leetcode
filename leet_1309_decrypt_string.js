var freqAlphabets = function(s) {
     let i = 0
     let z = s.length
     let res = ""
     while (i < z){
         if (i + 2 < z && s[i + 2] == '#'){
             let tmp = parseInt(s.substr(i, i + 2)) - 1 + "a".charCodeAt(0)
             res += String.fromCharCode(tmp)
             i += 3
             continue
         }
         let tmp = parseInt(s[i]) - 1 + "a".charCodeAt(0)
         res += String.fromCharCode(tmp)
         ++i
     }
    return res
};
