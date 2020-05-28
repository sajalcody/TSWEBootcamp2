// Link: https://leetcode.com/problems/subsets/

class Solution {
public:
    void subset(vector<int>& arr, int index, vector<int>& subSet, vector<vector<int> >& powerSet){
        powerSet.push_back(subSet);
        for (int i = index; i < arr.size(); i++){
            subSet.push_back(arr[i]);
            subset(arr, i + 1, subSet, powerSet);
            subSet.pop_back();

    }
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subSet;
        vector<vector<int> > powerSet;
        subset(nums, 0, subSet, powerSet);
        return powerSet;
    }
};