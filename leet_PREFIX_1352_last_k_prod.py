class ProductOfNumbers:

    def __init__(self):
        self.prefixprod = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.prefixprod = [1]
        else:
            self.prefixprod.append( num * self.prefixprod[-1] )

    def getProduct(self, k: int) -> int:
        N = len(self.prefixprod)
        if N < (k + 1):
            return 0
        return self.prefixprod[-1] // self.prefixprod[N - (k + 1)]


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)
