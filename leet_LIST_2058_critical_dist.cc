/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {

        ios_base::sync_with_stdio(false);
        vector<vector<int>(*)(ListNode*)> Solutions = {
            // InitialSoln,
            TryBeingSmarter,
        };
        return Solutions[0](head);
    }

    static vector<int> TryBeingSmarter(ListNode* head)
    {
        int prev = head->val;
        bool gotLeft = false;
        int left = -1;
        int lastSeen = -1;
        int mn = INT_MAX, mx = INT_MIN;
        ListNode * curr = head;
        ListNode * _next = head->next;

        if (_next == nullptr)
            return {-1, -1};
        int index = 2;
        while (_next->next)
        {
            curr = curr->next;
            _next = _next->next;
            if ((prev < curr->val && curr->val > _next->val)
            || (prev > curr->val && curr->val < _next->val))
            {
                if (gotLeft)
                {
                    mn = min(mn, index - lastSeen);
                    mx = max(mx, index - left);
                }
                else
                {
                    gotLeft = true;
                    left = index;
                }
                lastSeen = index;
            }
            prev = curr->val;
            index++;
        }
        if (mn == INT_MAX || mx == INT_MIN)
            return {-1, -1};
        return {mn, mx};
    }

    static vector<int> InitialSoln(ListNode* head)
    {
        vector<int> dis;
        int prev = head->val;
        ListNode * curr = head;
        ListNode * _next = head->next;
        // o --- o --- o --- o --- o
        // prev  ^     ^
        //       curr  _nxt
        if (_next == nullptr)
            return {-1, -1};
        int index = 2;
        while (_next->next)
        {
            curr = curr->next;
            _next = _next->next;
            if ((prev < curr->val && curr->val > _next->val)
            || (prev > curr->val && curr->val < _next->val))
            {
                // cout << index << ' ' ;
                dis.push_back(index);
            }
            prev = curr->val;
            index++;
        }
        if (dis.size() < 2)
            return {-1, -1};
        int mn = INT_MAX;
        int i = 0;
        sort(begin(dis), end(dis));
        while (++i < dis.size())
        {
            int d = dis[i] - dis[i - 1];
            mn = min(d, mn);
        }
        return {mn, dis[dis.size() - 1] - dis[0]};
    }
};
