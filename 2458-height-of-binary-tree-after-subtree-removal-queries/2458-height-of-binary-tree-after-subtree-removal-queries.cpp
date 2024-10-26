/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int depth, unordered_map<int, int>& nodeIndexMap,
             vector<int>& nodeDepths) {
        if (root == nullptr)
            return;

        nodeIndexMap[root->val] = nodeDepths.size();
        nodeDepths.push_back(depth);

        dfs(root->left, depth + 1, nodeIndexMap, nodeDepths);
        dfs(root->right, depth + 1, nodeIndexMap, nodeDepths);
    }

    int calculateSubtreeSize(TreeNode* root,
                             unordered_map<int, int>& subtreeSize) {
        if (root == nullptr)
            return 0;

        int leftSize = calculateSubtreeSize(root->left, subtreeSize);
        int rightSize = calculateSubtreeSize(root->right, subtreeSize);

        int totalSize = leftSize + rightSize + 1;
        subtreeSize[root->val] = totalSize;

        return totalSize;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> nodeIndexMap;

        unordered_map<int, int> subtreeSize;

        vector<int> nodeDepths;
        vector<int> maxDepthFromLeft;
        vector<int> maxDepthFromRight;

        dfs(root, 0, nodeIndexMap, nodeDepths);

        int totalNodes = nodeDepths.size();

        calculateSubtreeSize(root, subtreeSize);

        maxDepthFromLeft.push_back(nodeDepths[0]);
        maxDepthFromRight.push_back(nodeDepths[totalNodes - 1]);

        for (int i = 1; i < totalNodes; i++) {
            maxDepthFromLeft.push_back(
                max(maxDepthFromLeft[i - 1], nodeDepths[i]));
            maxDepthFromRight.push_back(
                max(maxDepthFromRight[i - 1], nodeDepths[totalNodes - i - 1]));
        }
        reverse(maxDepthFromRight.begin(), maxDepthFromRight.end());

        vector<int> results(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int queryNode = queries[i];
            int startIndex = nodeIndexMap[queryNode] - 1;
            int endIndex = startIndex + 1 + subtreeSize[queryNode];

            int maxDepth = maxDepthFromLeft[startIndex];
            if (endIndex < totalNodes) {
                maxDepth = max(maxDepth, maxDepthFromRight[endIndex]);
            }

            results[i] = maxDepth;
        }

        return results;
    }
};