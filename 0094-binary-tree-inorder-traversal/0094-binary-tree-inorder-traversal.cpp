class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        stack<TreeNode*> st;

        while (root != nullptr || !st.empty()) {

            // Go to the leftmost node
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }

            // Process the node
            root = st.top();
            st.pop();

            ans.push_back(root->val);

            // Move to right subtree
            root = root->right;
        }

        return ans;
    }
};