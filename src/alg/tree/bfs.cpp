#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> bfs(TreeNode *root) {
    if (!root)
        return {};
    std::queue<TreeNode *> q;
    std::vector<std::vector<int>> ans;
    q.push(root);

    while (!q.empty()) {
        std::vector<int> level;
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            TreeNode *curr = q.front();
            q.pop();
            level.push_back(curr->val);

            if (curr->left) {
                q.push(curr->left);
            }

            if (curr->right) {
                q.push(curr->right);
            }
        }
        ans.push_back(level);
    }

    return ans;
}

int main() {
    // build:      3
    //            / \
    //           9  20
    //              / \
    //             15  7
    TreeNode *root = new TreeNode(3,
        new TreeNode(9),
        new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    auto levels = bfs(root);
    for (auto &level : levels) {
        for (int v : level) std::cout << v << " ";
        std::cout << "\n";
    }

    std::vector<std::vector<int>> expected = {{3}, {9, 20}, {15, 7}};
    assert(levels == expected);

    assert(bfs(nullptr).empty());

    TreeNode *single = new TreeNode(1);
    assert(bfs(single) == std::vector<std::vector<int>>{{1}});

    std::cout << "all tests passed\n";
}
