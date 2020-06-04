// Link: https://leetcode.com/problems/reconstruct-itinerary/

class Solution {
public:
    vector<string> ans;
    void findItineraryHelper(string start, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& map) {
    while (!map[start].empty()) {
        string res = map[start].top();
        map[start].pop();
        findItineraryHelper(res, map);
    }
    ans.push_back(start);
}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ans.clear();
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> map;
        for (auto p = tickets.begin(); p != tickets.end(); p++) {
            map[(*p)[0]].push((*p)[1]);
        }
        findItineraryHelper("JFK", map);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};