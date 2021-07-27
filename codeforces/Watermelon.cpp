#include <iostream> // includes cin to read from stdin and cout to write to stdout

//https://codeforces.com/problemset/problem/4/A

bool watermelon(int a){
    if(a % 2 == 0 && a / 2 >= 2)
    return true;
    else
    return false;
}

using namespace std; // since cin and cout are both in namespace std, this saves some text
int main() {
    int t;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    bool ans = watermelon(t);
    if (ans)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

