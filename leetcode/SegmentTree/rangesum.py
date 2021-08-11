import sys
from math import ceil, log2 

class TreeNode:
    def __init__(self, value=0):
        self.left = None 
        self.right = None
        self.value = value


class SegmentTree:
    '''
    This SegmentTree stores sums of different ranges
    '''
    def __init__(self , nums):
        n = len(nums)
        
       # Height of segment tree
        x = (int)(ceil(log2(n)))
        # Maximum size of segment tree
        max_size = 2 * (int)(2**x) - 1; 
        
        self.left = 0
        self.right = n - 1
        
        self.tree = [-sys.maxsize]*(max_size)
        self.build_s_tree(nums , 0 , self.left , self.right)

        
    def build_s_tree(self , nums , index , L , R):
        '''
        This function builds SegmentTree
        => Here [L , R] is current node range
        '''
        if L == R : # Leaf-Node Condition
            self.tree[index] = nums[L]
        else:
            mid = (L + R) // 2
            self.tree[index] = self.build_s_tree(nums , 2 * index + 1 , L , mid) + self.build_s_tree(nums , 2 * index + 2 , mid + 1 , R)
        
        return self.tree[index]


class SegmentTree2:
    def __init__(self, nums):
        n = len(nums)

    def build_s_tree(self, nums, L, R):
        if L == R:
            treenode = TreeNode(nums[L])
        else:
            treenode = TreeNode()
            mid = (L+R) // 2
            treenode.left = self.build_s_tree(nums, L, mid)
            treenode.right = self.build_s_tree(nums, mid+1, R)
            treenode.value = treenode.left.value + treenode.right.value
        return treenode

    def update(self, treenode, L, R, i, diff):
        if i < L or i > R:
            return 
        treenode.value += diff
        mid = (L + R) // 2
        self.update(treenode.left, L, mid, i, diff)
        self.update(treenode.right, mid+1, R, i, diff)

nums = [i for i in range(15)]
s1 = SegmentTree(nums)
