class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr)
    {
        int s = arr.size();
        if (s < 3)  return true ;
        int i = -1;
        sort(arr.begin(), arr.end());
        while (++i < s - 2)
        {
            if (arr[i] - arr[i + 1] ^ arr[i + 1] - arr[i + 2])
                return false ;
        }
        return true ;
    }
};
