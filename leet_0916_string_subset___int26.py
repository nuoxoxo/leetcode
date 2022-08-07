class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        len1 = len(words1)
        len2 = len(words2)
        freq = [0] * 26
        a = ord('a')
        res = []
        for s in words2:
            temp = [0] * 26
            for c in s:
                asc = ord(c) - a
                temp[asc] += 1
                freq[asc] = max(freq[asc], temp[asc])
        for s in words1:
            temp = [0] * 26
            for c in s:
                temp[ord(c) - a] += 1
            i = 0
            while i < 26:
                if temp[i] < freq[i]:
                    break
                i += 1
            if i == 26:
                res.append(s)
        return res
