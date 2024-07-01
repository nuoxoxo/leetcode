class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        /*
        // IDEA: for each worker, assign a job of max profit

        // eg.1
        work(ers): 4,5,6,7
        level:  2, 4, 6, 8,10
        money: 10,20,30,40,50
                   ^ money-20 job with level-4 difficulty 
                      is the best for capacity-4 and capacity-6
                      ^ money-30 job with level-6 diffculty
                          worker-6 and worker-7 can take this job
        ---> res = 20 * 2 + 30 * 2

        // eg.2
        work(ers): 40,25,25
        level:    85,47,57
        money:    24,66,99
        ---> res=0 (every difficulty level exceeds anyone's capacity)
        */

        int N = difficulty.size();
        assert(N == profit.size());
        deque<pair<int, int>> Q;
        int i = -1;
        while (++i < N)
            Q.push_back({difficulty[i], profit[i]});
        sort(begin(Q), end(Q), [](auto & l, auto & r){ return l.first < r.first; });
        // for (auto p : Q) cout << p.first << ':' << p.second << endl;
        sort(begin(worker), end(worker));
        int res = 0;
        int curr = 0;
        for (int hp : worker)
        {
            while (!Q.empty() && hp >= Q.front().first)
            {
                curr = max(curr, Q.front().second);
                Q.pop_front();
            }
            // cout << "accepted/ " << hp << ' ' << curr << endl;
            res += curr;
        }
        return res;
    }
};
