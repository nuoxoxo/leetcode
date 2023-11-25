class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int hi = *max_element(arr.begin(), arr.end());
        int len = (int)arr.size();
        if (len <= k)
            return hi;
        int res = arr[0];
        int count = 0;
        int i = 0;
        while (++i < len)
        {
            if (res < arr[i])
            {
                count = 1;
                res = arr[i];
            }
            else
                count++;
            if (count == k)
                return res;
        }
        return hi;
    }
};
