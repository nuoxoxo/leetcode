class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (k < arr[0])
            return k;
        k = k - arr[0] + 1;
        int i = 0;
        while (++i < arr.size()) {
            int diff = arr[i] - arr[i - 1]
            if (diff == 1)
                continue ;
            if (diff > k)
                break ;
            k = k - diff + 1;
        }
        return arr[i - 1] + k;
    }
};
