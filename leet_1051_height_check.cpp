class Solution {
public:
    int heightChecker(vector<int>& h)
    {
        vector<int> k = h;
        int         i = -1, n = 0;

        sort(k.begin(), k.end());
        while (++i < k.size())
            if (k[i] != h[i])   n++ ;
        return n ;
    }
};
