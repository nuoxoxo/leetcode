class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
    {
        vector<vector<int>> res;
        int                 val, i;

        sort(arr.begin(), arr.end());
        if (arr.size() == 2)
        {
            res.push_back(arr);
            return (res);
        }
        val = 1e9;
        i = -1;
        while (++i < arr.size() - 1)
            val = val < arr[i+1]-arr[i] ? val : arr[i+1]-arr[i];
        i = -1;
        while (++i < arr.size() - 1)
            if (val == arr[i+1]-arr[i]) res.push_back({arr[i],arr[i+1]});

        return (res);
    }
};
