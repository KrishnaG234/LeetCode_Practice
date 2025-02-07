class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;  
        }

        for(auto it: freq){
            if(it.second > n/3){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};