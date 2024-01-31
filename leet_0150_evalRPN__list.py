class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        E = [] # init a stack is like init a list
        for t in tokens:
            if t == '+':
                E.append(E.pop() + E.pop())
            elif t == '-':
                E.append(-(E.pop() - E.pop()))
            elif t == '*':
                E.append(E.pop() * E.pop())
            elif t == '/':
                a, b = E.pop(), E.pop()
                E.append(int(b / a)) # round needed here, b // a is floor
            else:
                E.append(int(t))
        return E[0]
