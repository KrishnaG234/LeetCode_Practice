/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> q;
        vector<double> ans;

        q.push(root);
        q.push(NULL);
        double sum = 0;
        int cnt = 0;

        while(!q.empty()){
            TreeNode *front = q.front();
            q.pop();

            if(front == NULL){
                double avg = sum/cnt;
                ans.push_back(avg);
                cnt = 0, sum =0;
                if(q.size() > 0){
                    q.push(NULL);
                }
            }
            else{
                sum += front -> val;
                cnt++;

                if(front -> right){
                    q.push(front -> right);
                }

                if(front -> left){
                    q.push(front -> left);
                }
            }
        }
        return ans;
    }
};