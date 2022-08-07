class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        from collections import deque
        d = deque()
        for t in tokens:
            if t not in ['+','-','*','/']:
                d.append(int(t))
            else:
                if t is '+':
                    d.append(d.pop() + d.pop())
                elif t is '*':
                    d.append(d.pop() * d.pop())
                elif t is '-':
                    d.append(-(d.pop() - d.pop()))
                elif t is '/':
                    a = d.pop()
                    b = d.pop()
                    d.append(int(b / a))
        return d[0]
