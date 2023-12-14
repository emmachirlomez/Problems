#include<bits/stdc++.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void addNode(TreeNode* root, string &str) {
    if (root == NULL)
        return;
    str += to_string(root->val);
    if (root->left || root->right)
        str += '(', addNode(root->left, str), str += ')';
    if (root->right)
        str += '(', addNode(root->right, str), str += ')';
}

string tree2str(TreeNode* root) {
    string str = "";
    addNode(root, str);
    return str;
}

int main() {
    TreeNode node_4 = TreeNode(4);
    TreeNode nothing = TreeNode();
    TreeNode left = TreeNode(2, &node_4, &nothing);
    TreeNode right = TreeNode(3);
    TreeNode root = TreeNode(1, &left, &right);

    string ans = tree2str(&root);
    cout << ans << '\n';
    return 0;
}