class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n  =s.length();
        int maxLen = 0;
        unordered_map<char, int> charMap;
        int left = 0 ;

        for(int right = 0; right < n; right++){
            if(charMap.count(s[right]) == 0 || charMap[s[right]]<left){
                charMap[s[right]] = right;
                maxLen = max(maxLen, right - left + 1);
            }
            else{
                left = charMap[s[right]] + 1;
                charMap[s[right]] = right;
            }
        }

        return maxLen;
    }
};