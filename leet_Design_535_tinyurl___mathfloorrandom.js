/**
 * Encodes a URL to a shortened URL.
 *
 * @param {string} longUrl
 * @return {string}
 */
var encode = function(longUrl) {
    this.keys = new Array()
    this.dict = new Object()
    i = 31
    while (++i < 128) {
        this.keys.push(String.fromCharCode(i))
    }
    n = this.keys.length
    s = ''
    i = 0
    while (++i < 7) {
        s += Math.floor(Math.random() * n);
    }
    this.dict[s] = longUrl
    return s
};

/**
 * Decodes a shortened URL to its original URL.
 *
 * @param {string} shortUrl
 * @return {string}
 */
var decode = function(shortUrl) {
    return this.dict[shortUrl]
};

/**
 * Your functions will be called as such:
 * decode(encode(url));
 */
