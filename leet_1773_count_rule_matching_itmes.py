class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        res = 0
        for i in items:
            t, c, n = i[0], i[1], i[2]
            if (ruleKey == 'type' and t == ruleValue) \
            or (ruleKey == 'color' and c == ruleValue) \
            or (ruleKey == 'name' and n == ruleValue):
                res += 1
        return res
