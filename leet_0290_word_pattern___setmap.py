class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        a = s.split()
        set1 = set(pattern)
        set2 = set()
        for t in a:
            set2.add(t)
        if len(set1) != len(set2) or len(pattern) != len(a):
            return False
        D = {}
        for i in range(len(a)):
            print(i)
            if pattern[i] not in D:
                D[pattern[i]] = a[i]
            else:
                if D[pattern[i]] == a[i]:
                    continue
                return False
        return True
