// Link: https://leetcode.com/problems/beautiful-array/

class Solution {
public:

    vector <int> utilbeautifulArray (int n, map<int, vector <int>> &m){
        if(m.find(n) != m.end())
            return m[n];
        vector <int> odd = utilbeautifulArray((n+1)/2, m);
        vector <int> even = utilbeautifulArray(n/2, m);
        vector <int> mn(n);
        int i=0;
        for(int o: odd)
            mn[i++] = 2 * o - 1;
        for(int e : even)
            mn[i++] = 2 * e;
        m[n] = mn;
        return mn;

    }
    vector<int> beautifulArray(int N) {
        map <int, vector <int>> m;
        m[1] = vector <int> {1};
        return utilbeautifulArray(N, m);
    }
};