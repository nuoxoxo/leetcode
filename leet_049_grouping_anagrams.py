class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = []
        d = defaultdict(lambda: [])
        for s in strs:
            d["".join(sorted(s))].append(s)
        for key in d:
            res.append(d[key])
        return res
