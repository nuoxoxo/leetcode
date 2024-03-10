class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>(*)(vector<int> &, vector<int> &)> Solutions{
            // Two_pointers,
            // Using_set,
            Using_map,
        };
        return Solutions[0](nums1, nums2);
    }

    static vector<int> Using_set(vector<int>& n1, vector<int>& n2)
    {
        vector<int> res;
        set<int> S(n1.begin(), n1.end());
        for (int n: n2)
        {
            if (S.erase(n))
                res.push_back(n);
        }
        return res;
    }

    static vector<int> Two_pointers(vector<int>& n1, vector<int>& n2)
    {
        vector<int> res;
        sort(n1.begin(), n1.end());
        sort(n2.begin(), n2.end());
        int L = (int) n1.size(), R = (int) n2.size();
        int l = 0, r = 0;
        while (l < L && r < R) {
            if (n1[l] < n2[r]) {
                ++l;
                continue;
            } else if (n1[l] > n2[r]) {
                ++r;
                continue;
            } else if (!res.size() || res.back() != n1[l])
                res.push_back(n1[l]);
            ++l;
            ++r;
        }
        return res;
    }

    static vector<int> Using_map(vector<int>& n1, vector<int>& n2)
    {
        unordered_map<int, int> D;
        vector<int> res;
        int i = -1;
        while (++i < (int) n1.size())
            D[n1[i]]++;
        i = -1;
        while (++i < (int) n2.size())
        {
            if (D.find(n2[i]) != D.end())
            {
                res.push_back(n2[i]);
                D.erase(n2[i]);
            }
        }
        return res;
    }
};
