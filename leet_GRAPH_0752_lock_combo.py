class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        code = '0000'
        nogo = set(deadends)
        if target in nogo or code in nogo:
            return -1
        steps = defaultdict(int) # steps
        steps[code] = 0
        Q = deque() # todos
        Q.append(code)
        while Q:
            code = Q.popleft()
            if code == target:
                return steps[code]
            for i in range(4):
                n = int(code[i])
                for offset in [-1, 1]:
                    digit = str((n + offset) % 10)
                    _new = code[:i] + digit + code[i + 1:]
                    if _new == target:
                        return steps[code] + 1
                    if _new in nogo or _new in steps:
                        continue
                        # deadend OR been here already
                    steps[_new] = steps[code] + 1
                    Q.append(_new)
        return -1


