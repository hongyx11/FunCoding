#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#include <header.h>

template<typename T>
class SegmentTree_1D{
    public:
    vector<T> array;
    int N;
    SegmentTree_1D(vector<T> originarray){
        this->N = originarray.size();
        array.resize(4 * N);
        
    }
    void build(vector<int> &originarray, int v, 
    int begin, int end){

    }


};

#endif