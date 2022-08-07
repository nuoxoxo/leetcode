class Solution {
public:
    unordered_map<string, string>   dict;
    vector<char>                    keys;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string  s;
        int     i, n;
        if (keys.empty())
        {
            i = 31;
            while (++i < 128)
                keys.push_back((char) i);
        }
        n = keys.size();
        i = 0;
        while (++i < 7)
            s += keys[rand() % n];
        dict[s] = longUrl;
        return s ;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return dict[shortUrl]; 
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
