class Solution {
public:
    using PII = pair<int, int>;

    int maxFrequencyElements(vector<int>& nums) {
        vector<int(*)(vector<int>&)> Solutions {
            Best_complexity,
            // Space_heavy,
        };
        return Solutions[0](nums);
    }

    static int Best_complexity(vector<int>& nums) {
        unordered_map<int, int> D;
        int times = 0, top = -1;
        for (int & n: nums)
        {
            D[n]++;
            if (D[n] > top)
            {
                times = 0;
                top = D[n];
            }
            if (D[n] == top)
            {
                times++;
            }
        }
        return top * times;
    
    }

    static int Space_heavy(vector<int>& nums) {
        unordered_map<int, int> D;
        for (int n: nums)
            D[n]++;
        vector<PII> vp;
        for (auto & it: D)
            vp.push_back(it);
        sort(vp.begin(), vp.end(), cmp);
        int top = vp[0].second;
        int i = -1, res = 0;
        while (++i < (int)vp.size())
        {
            if (vp[i].second == top)
                res += top;
            else
                break;
        }
        return res;
    }

    static bool cmp(PII & l, PII & r)
    {
        return l.second > r.second;
    }
};
