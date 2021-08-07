
#include <header.h>

/*
1373. Maximum Sum BST in Binary Tree

Given a binary tree root, return the maximum sum of all keys of any sub-tree which 
is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/


struct RETSTRUCT {
    int minval;
    int maxval;
    int sumval;
    int valid;
    int empty;
};

class Solution {
public:
    int globalsum;
    int maxSumBST(TreeNode* root) {
        globalsum = 0;
        RETSTRUCT ret = helper(root);
        return globalsum;
    }
    RETSTRUCT helper(TreeNode * root){
        if(root == nullptr){
            RETSTRUCT ret;
            ret.valid = 1;
            ret.empty = 1;
            return ret;
        }
        if(root->left == nullptr && root->right == nullptr){
            RETSTRUCT ret;
            ret.minval = ret.maxval = ret.sumval = root->val;
            globalsum = max(globalsum, ret.sumval);
            ret.valid = 1;
            ret.empty = 0;
            return ret;
        }
        RETSTRUCT leftret = helper(root->left);
        RETSTRUCT rightret = helper(root->right);
        RETSTRUCT ret;
        ret.empty = 0;
        if(!leftret.empty && !rightret.empty){
            // both not empty
            ret.valid = leftret.valid && rightret.valid && 
            leftret.maxval < root->val && rightret.minval > root->val;
            if(!ret.valid) return ret;
            ret.minval = leftret.minval;
            ret.maxval = rightret.maxval;
            ret.sumval = leftret.sumval + root->val + rightret.sumval;
            globalsum = max(globalsum, ret.sumval);
        }else if(!leftret.empty){
            ret.valid = leftret.valid && leftret.maxval < root->val;
            if(!ret.valid) return ret;
            ret.minval = leftret.minval;
            ret.maxval = root->val;
            ret.sumval = leftret.sumval + root->val;
            globalsum = max(globalsum, ret.sumval);
        }else if(!rightret.empty){
            ret.valid = rightret.valid && rightret.minval > root->val;
            if(!ret.valid) return ret;
            ret.maxval = rightret.maxval;
            ret.minval = root->val;
            ret.sumval = rightret.sumval + root->val;
            globalsum = max(globalsum, ret.sumval);
        }
        return ret;
    }
};


int main(){
    
}