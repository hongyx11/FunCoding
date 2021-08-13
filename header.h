#ifndef HEADER_H
#define HEADER_H

#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right):
    val(x), left(left), right(right) {}
};


#endif 