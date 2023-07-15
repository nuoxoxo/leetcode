class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff)
    {
        unordered_map<int, int> dict;
        for (int & n : arr)
        {
            dict[n] = dict[n - diff] + 1;
        }
        return (*max_element(
            dict.begin(),
            dict.end(),
            [](const pair<int, int> & L, const pair<int, int> & R) {
                return L.second < R.second;
        })).second;
    } 
};
