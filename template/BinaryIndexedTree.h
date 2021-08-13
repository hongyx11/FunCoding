#ifndef BINARY_INDEXED_TREE_H
#define BINARY_INDEXED_TREE_H

#include <header.h>

class BinaryIndexedTree{
public:
    vector<int> arrays;
    vector<int> nums;
    void Init(vector<int> &nums);
    int PrefixSum(int index);
    void UpdateTree(int index, int value);
    
private:
    void BuildTree();
};

#endif