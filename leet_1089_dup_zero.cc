class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i = -1;
        while (++i < arr.size() - 1)
        {
            if ( !arr[i])
            {
                arr.insert(arr.begin() + i + 1, 0);
                arr.pop_back();
                ++i;
            }
        }
    }
};
