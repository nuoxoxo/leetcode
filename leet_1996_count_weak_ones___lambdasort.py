class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        properties.sort(key=lambda arr: (-arr[0], arr[1]))
        res = 0
        top = properties[0][1]
        for _, second in properties:
            if second < top:
                res += 1
            else:
                top = second
        return res
