class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        n = len(products)
        products.sort()
        res = []
        L, R = 0, n - 1
        for i, c in enumerate(searchWord):
            while L <= R and (i > len(products[L]) - 1 or products[L][i] < c):
            # while L <= R and (products[L][i] < c or i > len(products[L]) - 1):
                L += 1
            while L <= R and (i > len(products[R]) - 1 or products[R][i] > c):
            # while L <= R and (products[R][i] > c or i > len(products[R]) - 1):
                R -= 1
            if L > R:
                res.append([])
            else:
                end = min(L + 3, R + 1)
                res.append(products[L : end])
        return res
        
