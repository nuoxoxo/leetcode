class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        x = 0
        for s in operations:
            if '++' in s:
                x += 1
                continue
            if '--' in s:
                x -= 1
                continue
        return x
