// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:

    int searchUtil (int l, int r, vector <int> nums, int target){
        if (l > r)
            return -1;
        int mid = (l+r)/2;
        if (nums[mid] == target)
            return mid;
        if (nums[l] <= nums[mid]){
            if (target >= nums[l] && target < nums[mid])
                r = mid-1;
            else
                l = mid+1;
        }
        else{
            if (target > nums[mid] && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return searchUtil(l,r,nums,target);
    }
    int search(vector<int>& nums, int target) {
        return searchUtil (0, nums.size() - 1, nums, target);
    }
};