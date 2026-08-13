class Solution {
    struct Node {
        int len;
        int leftMax;
        int rightMax;
        int best;
        char leftChar;
        char rightChar;

        Node() {
            len = 0;
            leftMax = rightMax = best = 0;
            leftChar = rightChar = '#';
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Initially, best comes from either side
        res.leftMax = a.leftMax;
        res.rightMax = b.rightMax;
        res.best = max(a.best, b.best);

        // Check if the two parts can be joined
        if (a.rightChar == b.leftChar) {

            // A repeating substring crossing the boundary
            res.best = max(res.best, a.rightMax + b.leftMax);

            // Prefix extends through the right side
            if (a.leftMax == a.len) {
                res.leftMax = a.len + b.leftMax;
            }

            // Suffix extends through the left side
            if (b.rightMax == b.len) {
                res.rightMax = b.len + a.rightMax;
            }
        }

        return res;
    }

    void build(string &s, int node, int l, int r) {
        if (l == r) {
            tree[node].len = 1;
            tree[node].leftMax = 1;
            tree[node].rightMax = 1;
            tree[node].best = 1;
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];
            return;
        }

        int mid = (l + r) / 2;

        build(s, node * 2, l, mid);
        build(s, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node].leftChar = c;
            tree[node].rightChar = c;
            tree[node].leftMax = 1;
            tree[node].rightMax = 1;
            tree[node].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        tree.resize(4 * n + 5);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};