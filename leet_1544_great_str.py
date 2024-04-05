class Solution:
    def makeGood(self, s: str) -> str:
        return [
            # self.Using_stack_like,
            # self.Linear_scan_and_remove,
            self.Best_string_based_soln,
        ][0](s)

    def Best_string_based_soln(self, s: str) -> str:
        res = ''
        for c in s:
            if res != '' and c != res[-1] and c.lower() == res[-1].lower():
                res = res[:-1]
            else:
                res += c
        return res

    def Linear_scan_and_remove(self, s: str) -> str:
        dq = list(s)
        for i in range(len(dq) - 1):
            l, r = dq[i], dq[i + 1]
            if l != r and l.lower() == r.lower():
                dq = dq[:i] + dq[i + 2:]
                i -= 1
        return ''.join(dq)

    def Using_Stack_like(self, s: str) -> str:
        dq = []
        for c in s:
            dq.append(c)
            if len(dq) > 1 and dq[-1] != dq[-2] and dq[-1].lower() == dq[-2].lower():
                dq.pop()
                dq.pop()
        return ''.join(dq)
