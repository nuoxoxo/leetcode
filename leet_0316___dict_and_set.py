class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
      seen = set()
      count = defaultdict(int)
      res = ''
      for c in s:
        count[c] += 1
      for c in s:
        if c not in seen:
          while res != '' and ord(res[-1]) > ord(c) and count[res[-1]] > 1:
            seen.remove(res[-1])
            count[res[-1]] -= 1
            res = res[:-1]
          seen.add(c)
          res += c
        else:
          count[c] -= 1
      return res

