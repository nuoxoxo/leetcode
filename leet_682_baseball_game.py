class Solution:
    def calPoints(self, ops: List[str]) -> int:
        p = []
        for op in ops:
            if op == '+':
                p.append(p[-1] + p[-2])
            elif op == 'C':
                p.pop()
            elif op == 'D':
                p.append(2 * p[-1])
            else:
                p.append(int(op))
        return sum(p)
