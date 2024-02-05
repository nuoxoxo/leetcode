class Solution:
    def firstUniqChar(self, s: str) -> int:
        return [
            self.Solution_4_constant_space_2pass,
            # self.Solution_3_zero_space,
            # self.Solution_2_rfind,
            # self.Solution_1_using_two_lists,
        ][ 0 ]( s )

    def Solution_4_constant_space_2pass(self, s: str) -> int:
        D = [0] * 26
        a = ord('a')
        for c in s:
            D[ ord(c) - a ] += 1
        for i, c in enumerate(s):
            if D[ ord(c) - a ] == 1:
                return i
        return -1


    def Solution_3_zero_space(self, s: str) -> int:
        for i, c in enumerate(s):
            if i == len(s) - 1 and c not in s[:i] \
            or i == 0 and c not in s[1:] \
            or not c in s[:i] + s[i + 1:]:
                return i
        return -1


    def Solution_2_rfind(self, s: str) -> int:
        for c in s:
            idx = s.find(c)
            if idx != -1 and idx == s.rfind(c):
                return idx
        return -1

    def Solution_1_using_two_lists(self, s: str) -> int:
        seen, dupl = [], []
        for c in s:
            if c in seen and c in dupl:
                    dupl.remove(c)
            elif c not in seen:
                dupl.append(c)
                seen.append(c)
        if not dupl:
            return -1
        return s.index(dupl[0])

