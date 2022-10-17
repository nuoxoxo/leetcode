class Solution {
public:
    bool checkIfPangram(string s)
    {
        std::set<int>   S;

        for (char c : s)
            S.insert(c);
        return (S.size() == 26);
    }
};
