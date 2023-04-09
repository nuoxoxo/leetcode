class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long suc) {
        
        vector<int> v(s.size(), 0);
        int i = -1;
        sort(p.begin(),p.end());
        while (++i < (int) s.size())      
        {
            int h = p.size() - 1;
            int l = 0;
            int mid;
            while (l <= h)
            {
                mid = l + (h - l) / 2;
                if ((long long) s[i] * (long long) p[mid] >= suc)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            v[i] = p.size() - 1 - h;
        }
        return v;
    }
};
