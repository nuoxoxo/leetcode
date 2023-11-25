class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        // way 2 : greedy . mod arr in place 
        arr[0] = 1;
        int i = 0;
        int res = 1;
        while (++i < arr.size())
        {
            if (arr[i] > arr[i - 1])
                arr[i] = arr[i - 1] + 1;
            res = max(res, arr[i]);
        }
        return res;

        // way 1 : simple approach
        /*
        int res = 0;
        for (int n: arr)
            res = min(res + 1, n);
        return res;
        */
    }
};
