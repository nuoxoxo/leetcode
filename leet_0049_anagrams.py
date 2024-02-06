class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = []
        D = defaultdict(list)
        for s in strs:
            D[ ''.join(sorted(s)) ].append(s)
        return list(D.values())
