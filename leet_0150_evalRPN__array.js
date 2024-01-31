var evalRPN = function(tokens) {
    E = []
    for (let t of tokens){
        if (t == '+')
            E.push(E.pop() + E.pop())
        else if (t == '-')
            E.push(-(E.pop() - E.pop()))
        else if (t == '*')
            E.push(E.pop() * E.pop())
        else if (t == '/'){
            a = E.pop()
            b = E.pop()
            E.push(parseInt(b / a))
        }
        else
            E.push(parseInt(t))
    }
    return E[0]
};
