var interpret = function(command) {
    let len = command.length
    if (len == 1)   return "G"
    if (len == 2)   return "o"
    let s = ""
    let i = 0
    while (i < len){
        let c = command[i]
        if (c == 'G'){
            s += 'G'
            ++i
        } else if (c == '('){
            ++i
            c = command[i]
            if (c == ')'){
                s += 'o'
                ++i
            } else {
                s += "al"
                i += 3
            }
        }
    }
    return s
};
