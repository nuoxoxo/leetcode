class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        d = dict()
        a = ord('a')
        i = 0
        for c in key:
            if 0 <= ord(c) - a <= 26 and c not in d:
                d[c] = chr(i + a)
                i += 1
        # print(''.join(str(c) for c in d.keys())) # should be 'thequick...'
        # print(''.join(str(c) for c in d.values())) # should be 'abc...'
        res = ''
        for c in message:
            if 0 <= ord(c) - a <= 26:
                res += d[c]
            else:
                res += c
        return res
