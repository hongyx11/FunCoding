#include <header.h>
/*
1008. Construct Binary Search Tree from Preorder Traversal

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
*/

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return nullptr;
        TreeNode * root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);
        int idx = 1;
        while(idx != preorder.size()){
            if(st.empty() || preorder[idx] < st.top()->val){
                TreeNode *tmp = new TreeNode(preorder[idx]);
                st.top()->left = tmp;
                st.push(tmp);
                idx++;
            }else{
                TreeNode * prev;
                while(!st.empty() && preorder[idx] > st.top()->val){
                    prev = st.top();
                    st.pop();
                }
                prev->right = new TreeNode(preorder[idx]);
                idx++;
            }
        }
    }
};

int main(){

}