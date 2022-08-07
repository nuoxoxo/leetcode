class Solution {
public:
    bool canReach(vector<int>& arr, int start)
    {
        int     L, R;

        if (arr[start] == -1)   return (false);
        if (!arr[start])        return (true);
        L = start - arr[start];
        R = start + arr[start];
        arr[start] = -1;

        return ((L > -1 && canReach(arr, L)) ||
        (R < arr.size() && canReach(arr, R)));
    }
};
