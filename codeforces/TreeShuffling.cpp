#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

//https://codeforces.com/problemset/problem/4/A

bool treeshuffling(int n, int *a, int *b, int *c){
    if(a % 2 == 0 && a / 2 >= 2)
    return true;
    else
    return false;   
}


int main() {
    int n;
    cin >> n;
    int * aptr = new int[n];
    int * bptr = new int[n];
    int * cptr = new int[n];

    bool ans = treeshuffling(t);
    if (ans)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

