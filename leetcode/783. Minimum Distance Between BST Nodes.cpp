//https://leetcode.com/problems/minimum-distance-between-bst-nodes/submissions/899878420/




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
#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        // Step 1: Traverse the BST and store node values in a vector
        vector<int> nodes;
        inorder(root, nodes);
        
        // Step 2: Sort the vector
        sort(nodes.begin(), nodes.end());
        
        // Step 3: Compute the minimum difference between adjacent elements
        int min_diff = INT_MAX;
        for (int i = 0; i < nodes.size() - 1; i++) {
            int diff = abs(nodes[i+1] - nodes[i]);
            if (diff < min_diff) {
                min_diff = diff;
            }
        }
        
        return min_diff;
    }
    
private:
    void inorder(TreeNode* node, vector<int>& nodes) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, nodes);
        nodes.push_back(node->val);
        inorder(node->right, nodes);
    }
};
