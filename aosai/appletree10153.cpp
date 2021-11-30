/**************
有一棵二叉苹果树，如果数字有分叉，一定是分两叉，即没有只有一个儿子的节点。
这棵树共N个节点，标号 1至N ，
树根编号一定为1。
我们用一根树枝两端连接的节点编号描述一根树枝的位置。一棵有四根树枝的苹果树，因为树枝太多了，
需要剪枝。但是一些树枝上长有苹果，给定需要保留的树枝数量，求最多能留住多少苹果。
**************/

#include <header.h>


struct NodeStruct {
    int id;
    int appnum;
    NodeStruct * left;
    NodeStruct * right;
    bool haschild;
    NodeStruct(int id, int appnum, NodeStruct * left = nullptr, 
    NodeStruct * right = nullptr, bool haschild = false)
    :id(id),appnum(appnum),left(left),right(right),haschild(haschild){}
};

void buildtree(NodeStruct * tree){

}

int main(){
    int N;
    scanf("%d", &N);
    cout << N << endl;
    NodeStruct ** treevec = new NodeStruct*[N+1];
    REP(i, 0, N-1){
        int n1, n2, n3;
        scanf("%d %d %d", &n1, &n2, &n3);
    } 
}