class Solution {
public:
    string reverseWords(string s)
    {
        string          res, tmp;
        stringstream    ss(s);
        vector<string>  arr;
        while (ss >> tmp)
            arr.push_back(tmp);
        reverse(arr.begin(), arr.end());
        int i = -1, n = arr.size();
        while (++i < n)
        {
            res += arr[i];
            if (i != n - 1)
                res += ' ';
        }
        return res ;
    }
};
