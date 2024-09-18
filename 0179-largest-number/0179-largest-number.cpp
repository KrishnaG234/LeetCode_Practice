    bool comp(int x, int y) {
        string a = to_string(x);
        string b = to_string(y);

        if ((a + b) > (b + a)) {
            return true;
        }
        return false;
    }

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);

        if (nums[0] == 0) {
            return "0";
        }

        string ans = "";
        for (int num : nums) {
            ans += to_string(num);
        }

        return ans;
    }
};