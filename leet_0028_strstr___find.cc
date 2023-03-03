class Solution {
public:
    int strStr(string haystack, string needle)
    {
        size_t  it = haystack.find(needle);

        if (it == string::npos)
            return -1;
        return it;

    }
};
