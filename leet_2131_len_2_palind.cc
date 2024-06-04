class Solution {
public:
    int longestPalindrome(vector<string>& words)
    {
        /*unordered_*/map<string, int> D;
        for (string word : words)
            ++D[word];

        int res = 0;
        int mid = 0;
        auto p = begin(D);
        int i = 0;
        while (p != end(D))
        {
            ++i;
            string key = p->first;
            int count = p->second;
            // case : 'gg'
            if (key[0] == key[1])
            {
                // cout << key <<  ' ' << count / 2 << endl;
                res += (count / 2) * 2 * 2;
                if (count % 2)
                    mid = 2;
            }
            // case : 'xy'
            //  mind the over-count
            else if (key[0] < key[1])
            {
                string rev(key);
                reverse(begin(rev), end(rev));
                // print(k, v, counter[k[::-1]])
                /*
                bi 2 0
                bg 1 3
                */
                res += min(count, D[rev]) * 2 * 2;
            }
            // cout << i << ' ' << key << ' ' << (key[0] < key[1]) << endl;
            p++;
        }
        return res + mid;
    }
};
