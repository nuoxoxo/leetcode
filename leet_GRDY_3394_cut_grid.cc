class Solution {
public:
    // #define vector<int> vi
    #define vi vector<int>
    bool checkValidCuts(int n, vector<vector<int>>& rectangles)
    {
        vector<bool(*)(vector<vi> &)> Solutions {
            Twopass,
        };
        return Solutions[0](rectangles);
    }

    static bool Twopass(vector<vi>&rectangles)
    {
        vector<vi> h, v;
        for (auto q : rectangles) {
            h.push_back(vi{q[0],q[2]});
            v.push_back(vi{q[1],q[3]});
        }
        std::function<bool(vector<vi> &)> f = [&](vector<vi> & v) {
            sort(v.begin(), v.end(), [](const vi&l, const vi&r){
                return l[0] == r[0] ? l[1] < r[1] : l[0] < r[0];
            });
            int R = v[0][1];
            int ok = 0;
            for (auto lr : v) {
                int l = lr[0], r = lr[1];
                if (R <= l) {
                    if (++ok > 1) return true;
                }
                R = max(R,r);
            }
            return false;
        };
        return f(v) || f(h);
    }
};
