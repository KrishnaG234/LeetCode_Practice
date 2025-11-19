class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            int l = dp[i - 1] + cost[i - 1];
            int r = dp[i - 2] + cost[i - 2];

            dp[i] = min(l, r);
        }

        return dp[n];
    }
};