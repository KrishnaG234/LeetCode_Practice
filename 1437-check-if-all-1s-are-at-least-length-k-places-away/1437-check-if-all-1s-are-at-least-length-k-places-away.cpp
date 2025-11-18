class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last1 = k;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                last1++;
            }
            else if(nums[i] == 1){
                if(last1 < k){
                    return false;
                }
                else{
                    last1 = 0;
                }
            }
        }

        return true;
    }
};