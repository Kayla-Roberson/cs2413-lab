/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int heightHelper(struct TreeNode* node, int min, int max, bool useMin, bool useMax){
    if(node == NULL){
        return 0;
    }

    if(useMin && node->val <= min) return -1;
    if(useMax && node->val >= max) return -1;
    int leftHeight  = heightHelper(node->left,  min, node->val, useMin, true);
    int rightHeight = heightHelper(node->right, node->val, max, true, useMax);
    if(leftHeight == -1 || rightHeight == -1){
        return -1;
    }
    int diff = leftHeight - rightHeight;
    if(diff > 1 || diff < -1) return -1;
    if(leftHeight > rightHeight){
        return 1 + leftHeight;
    }else{
        return 1 + rightHeight;
    }
}

bool isAVL(struct TreeNode* root) {
    if(root == NULL){
        return true;
    }
    // Pass int min/max as bounds
    int bf = heightHelper(root, 0, 0, false, false);
    if(bf == -1){
        return false;
    }else{
        return true;
    }
}
