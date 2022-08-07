class Solution {
public:
    bool checkIfExist(vector<int>& arr)
    {
        int n = (int) arr.size();
        int i = -1, j, temp;
        while (++i < n)
        {
            temp = arr[i] * 2;
            j = -1;
            while (++j < n)
                if (j ^ i && temp == arr[j])
                    return true;
        }
        return false;
    }
};
