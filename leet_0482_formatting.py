class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        a = [c for c in s][::-1]
        print(a)
        res = ''
        count = 0
        for c in a:
            # print(count, c)
            if c == '-':
                continue
            if count ^ k:
                count += 1
            else:
                count = 1
                res += '-'
            res += c.upper()
        if res != '' and res[-1] == '-':
            res = res[len(res) - 1]
        # print(res)
        return res[::-1]
