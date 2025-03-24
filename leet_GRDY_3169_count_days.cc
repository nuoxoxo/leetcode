class Solution {
public:
    #define vi vector<int>
    int countDays(int days, vector<vector<int>>& meetings)
    {
        vector<int(*)(int,vector<vi>&)> Solutions{
            Greedy,
        };
        return Solutions[0](days,meetings);
    }

    static int Greedy(int days, vector<vi> & meetings){
        sort(meetings.begin(), meetings.end(), [](const vi&l, const vi&r){
            return l[0] == r[0] ? l[1] < r[1] : l[0] < r[0];
        });
        int R = 0; // current furthest end
        int ok = 0; // left bulk of free days
        for (auto lr : meetings){
            int l = lr[0] - 1, r = lr[1];
            if (R < l)
                ok += l - R;
            R = R > r ? R : r;
        }
        return ok + days - R;
    }
};
