// Link: https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    double eDis(vector <int> p){
        return sqrt(p[0] * p[0] + p[1] * p[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue <pair <double, vector <int> > > h;
        vector<vector<int>> ans;
        int n = p.size();
        for (int i = 0; i < k; i++)
            h.emplace(eDis(p[i]), p[i]);
        for(int i = k; i < n; i++){
            double dis = eDis(p[i]);
            if(h.top().first > dis){
                h.pop();
                h.emplace(dis, p[i]);
            }
        }
        while(k-- > 0){
            ans.push_back(h.top().second);
            h.pop();
        }
        return ans;
    }
};