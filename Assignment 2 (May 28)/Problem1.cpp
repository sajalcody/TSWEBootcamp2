// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") 
            return 0;
        int maxLen = 1, low = 0, i;
        map <char,int> a;
        for (i = 0; s[i] !='\0' ; i++){
            if (a.find(s[i]) != a.end() && low <= a[s[i]]){
                maxLen = i - low > maxLen ?  i - low : maxLen;
                low = a[s[i]] + 1;
            }
            a[s[i]] = i;
        }
        return max(i - low, maxLen);
    }
};