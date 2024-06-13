class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        vector<vector<int>(*)(vector<int>&, vector<int>&)> solutions {
            // Frequency_map,
            Index_map,
        };
        return solutions[0](arr1, arr2);
    }

    static vector<int> Index_map(vector<int>& arr1, vector<int>& arr2)
    {
        unordered_map<int, int> D;
        int i = -1;
        while (++i < arr2.size())
            D[arr2[i]] = i;
        auto cmp = [&D](int l, int r) {
            auto lit = D.find(l);
            auto rit = D.find(r);
            if (lit != D.end() && rit != D.end())
                return lit->second < rit->second;
            else if (lit != D.end())
                return true;
            else if (rit != D.end())
                return false;
            return l < r;
        };
        sort(begin(arr1), end(arr1), cmp);
        return arr1;
    }

    static vector<int> Frequency_map(vector<int>& arr1, vector<int>& arr2)
    {
        unordered_map<int, int> D;
        vector<int> tail, res;
        for (int n : arr1)
        {
            if (find(begin(arr2), end(arr2), n) == arr2.end())
                tail.push_back(n);
            else
                D[n]++;
        }
        sort(tail.begin(), tail.end());
        for (int n : arr2)
            res.insert(res.end(), D[n], n);
        res.insert(res.end(), tail.begin(), tail.end());
        return res;
    }
};
