class Codec:
    
    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        self.k = [chr(i) for i in range(32, 128)]
        self.d = dict()
        shortUrl = ''.join(random.choices(self.k, weights=None, k=6))
        
        self.d[shortUrl] = longUrl
        return shortUrl
        

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return self.d[shortUrl]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
