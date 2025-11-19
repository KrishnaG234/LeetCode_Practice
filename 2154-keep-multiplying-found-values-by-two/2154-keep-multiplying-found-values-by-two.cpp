class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        while(mp[original]>0){
            original*=2;
        }

        return original;
    }
};