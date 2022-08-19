class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        table = [''] * 26
        a = ord('a')
        i = 0
        check = set()
        for c in key:
            o = ord(c) - a
            # print(c, asc, i)
            if 0 <= o <= 26 and c not in check:
                check.add(c)
                table[i] = c
                i += 1
        # print(''.join(str(c) for c in table))
        res = ''
        for c in message:
            o = ord(c) - a
            if 0 <= o <= 26:
                res += chr(table.index(c) + a)
            else:
                res += c
        return res
