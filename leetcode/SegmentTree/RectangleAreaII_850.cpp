#include <header.h>

/*

850. Rectangle Area II

We are given a list of (axis-aligned) rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2] , 
where (xi1, yi1) are the coordinates of the bottom-left corner, and (xi2, yi2) 
are the coordinates of the top-right corner of the ith rectangle.

Find the total area covered by all rectangles in the plane. 
Since the answer may be too large, return it modulo 109 + 7.

https://leetcode.com/problems/rectangle-area-ii/

*/

#include <header.h>

#include "segmenttree.h"

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<int> tmpval;
        SegmentTree seg(tmpval);
    }
};

int main(){

}