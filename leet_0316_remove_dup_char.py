class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        visited = [False] * 26
        counter = [0] * 26
        # print(visited, count, sep='\n')
        size = len(s)
        res = ""
        a = ord('a')
        for c in s:
            counter[ord(c) - a] += 1
        for c in s:
            n = ord(c)
            if visited[n - a] is True:
                counter[n - a] -= 1
            else:
                while res != "" and ord(res[-1]) >= n and counter[ord(res[-1]) - a] > 1:
                    counter[ord(res[-1]) - a] -= 1
                    visited[ord(res[-1]) - a] = False
                    res = res[:-1]
                res += c
                visited[n - a] = True
        return res
