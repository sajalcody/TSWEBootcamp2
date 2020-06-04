// Link: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size(), cumSum = 0;
        set<pair<int, int>> mm;
        mm.insert({0, -1});
        
        int minn = INT_MAX;
        for(int i = 0; i < n; i++) {
            cumSum += a[i];
            set<pair<int, int>>::iterator it = mm.insert(make_pair(cumSum, i)).first;
            while (next(it) != mm.end()) {
                auto ahead = next(it);
                if (ahead->first >= it->first and ahead->second <= it->second)
                    mm.erase(ahead);
                else it = ahead;
            }

            auto up = mm.upper_bound(make_pair(cumSum - k, INT_MAX));
            if (up != mm.begin()) {
                auto before = prev(up);
                minn = min(minn, i - before->second);    
            }
        }
        
        return minn == INT_MAX? -1: minn;
    }
};